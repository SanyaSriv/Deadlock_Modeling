/*Defining the macros here*/
const
  NumberNodes: 4;
  BufferSpace: 3;

Type 
    MessageState: enum {empty, response, request, fwd_request, fwd_response};
    NodeIDs: scalarset(NumberNodes); 

/*TODO: Change the way in which the src_hops are updated*/

Message: Record
    msg_type: MessageState;
    dest_hops: 0..NumberNodes;     /*Hops left to the destination - decrement this as you move along*/
    src_hops: 0..NumberNodes;       /*Hops left to the source - increment this as you move along*/
    End;
    /*I am purposefully not including a direction here because it will reduce
    the scope of symmetry.*/

/*Making a node in here*/
Node: Record
    IncomingQueue_CC: array[0..BufferSpace-1] of Message;
    IncomingQueue_AC: array[0..BufferSpace-1] of Message;
    TailPointer_CC: 0..BufferSpace;
    TailPointer_AC: 0..BufferSpace;
    FrontPointer: 0..1;
    Next_CC: NodeIDs;
    Next_AC: NodeIDs;
End;

var 
    Nodes: array[NodeIDs] of Node;

procedure SendRequest(src_nid:NodeIDs; next_hop_length:1..NumberNodes; direction:0..1);
    /*Send a request -
    src_nid --> source node that is sending the request
    next_hop_length --> how far the next node is
    1. If the actual destination of the message is the next hop, then send a request.
    2. If the next hop is not the final destination, send a forwarded request.
    The message should always have the original source and destination. */
    var msg_to_send: Message;
begin
    if next_hop_length = 1 then
        msg_to_send.msg_type := request; /*Send a request*/
    else
        msg_to_send.msg_type := fwd_request; /*Send a forwarded request*/
    endif;

    msg_to_send.src_hops := next_hop_length; /*Keep decreasing this as you go along*/
    msg_to_send.dest_hops := next_hop_length - 1; /*How far it needs to travel*/

    if direction = 0 then
        /*Take the clockwise direction*/
        Nodes[Nodes[src_nid].Next_CC].IncomingQueue_CC[Nodes[Nodes[src_nid].Next_CC].TailPointer_CC] := msg_to_send;
        Nodes[Nodes[src_nid].Next_CC].TailPointer_CC := Nodes[Nodes[src_nid].Next_CC].TailPointer_CC + 1;
    else
        /*Take the anti-clockwise direction*/
        Nodes[Nodes[src_nid].Next_AC].IncomingQueue_AC[Nodes[Nodes[src_nid].Next_AC].TailPointer_AC] := msg_to_send;
        Nodes[Nodes[src_nid].Next_AC].TailPointer_AC := Nodes[Nodes[src_nid].Next_AC].TailPointer_AC + 1;
    endif;
end;

Procedure ProcessFwdRequest(src_nid:NodeIDs; direction:0..1);
/*
src_nid --> source node that is currently holding the fwd_request message
Process a forwarded request - 
 1. If the destination node id we have is not the final destination of the message
    then just pass the request along the chain.
 2. If it is the final destination, then pass a request and not a forwared request
    SEND THINGS IN THE SAME DIRECTION
 */
   var msg_to_send: Message;
begin
    if direction = 0 then
        /*Keep things clockwise*/
        if  Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].dest_hops = 1 then
            msg_to_send.msg_type := request; /*Send a request because the next hop is the actual destination*/
        else
            msg_to_send.msg_type := fwd_request; /*Send a fwd_request because the next hop is not the actual destination*/
        endif; 
        /*Decrease both the destination hop and the source hop count*/
        msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].dest_hops - 1;
        msg_to_send.src_hops := Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].src_hops;
        /* Shift messages in the source buffer */
        for i := 1 to Nodes[src_nid].TailPointer_CC - 1 do
            Nodes[src_nid].IncomingQueue_CC[i - 1] := Nodes[src_nid].IncomingQueue_CC[i];
        endfor;

        Nodes[src_nid].TailPointer_CC := Nodes[src_nid].TailPointer_CC - 1;
        Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].TailPointer_CC].msg_type := empty;

        Nodes[Nodes[src_nid].Next_CC].IncomingQueue_CC[Nodes[Nodes[src_nid].Next_CC].TailPointer_CC] := msg_to_send;
        Nodes[Nodes[src_nid].Next_CC].TailPointer_CC := Nodes[Nodes[src_nid].Next_CC].TailPointer_CC + 1;
    else 
        /*Keep things clockwise*/
        if  Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].dest_hops = 1 then
            msg_to_send.msg_type := request; /*Send a request because the next hop is the actual destination*/
        else
            msg_to_send.msg_type := fwd_request; /*Send a fwd_request because the next hop is not the actual destination*/
        endif; 
        /*Decrease both the destination hop and the source hop count*/
        msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].dest_hops - 1;
        msg_to_send.src_hops := Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].src_hops;
        /* Shift messages in the source buffer */
        for i := 1 to Nodes[src_nid].TailPointer_AC - 1 do
            Nodes[src_nid].IncomingQueue_AC[i - 1] := Nodes[src_nid].IncomingQueue_AC[i];
        endfor;

        Nodes[src_nid].TailPointer_AC := Nodes[src_nid].TailPointer_AC - 1;
        Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].TailPointer_AC].msg_type := empty;

        Nodes[Nodes[src_nid].Next_AC].IncomingQueue_AC[Nodes[Nodes[src_nid].Next_AC].TailPointer_AC] := msg_to_send;
        Nodes[Nodes[src_nid].Next_AC].TailPointer_AC := Nodes[Nodes[src_nid].Next_AC].TailPointer_AC + 1;
    endif;
End;

Procedure ProcessRequest(src_nid: NodeIDs; direction:0..1);
    /*
    src_nid --> node that is holding the incoming request
    Process a request -
    1. If this is a request, then it implies the message is already at its destination
       so we either need to send a response or a forwarded response based on whether
       the original destination is the next hop.
    */
  
  /*Make the response message that should be sent*/
   var msg_to_send: Message;
Begin
    if direction = 0 then
        /*Tke the message from the clockwise buffer but put it in the other node's
        anti_clockwise buffer*/
        if Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].src_hops = 1 then
            msg_to_send.msg_type := response;
        else
            msg_to_send.msg_type := fwd_response;
        endif;

        msg_to_send.src_hops :=  Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].src_hops;
        msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].dest_hops;

        /* Shift messages in the source buffer */
        for i := 1 to Nodes[src_nid].TailPointer_CC - 1 do
            Nodes[src_nid].IncomingQueue_CC[i - 1] := Nodes[src_nid].IncomingQueue_CC[i];
        endfor;

        Nodes[src_nid].TailPointer_CC := Nodes[src_nid].TailPointer_CC - 1;
        Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].TailPointer_CC].msg_type := empty;

        Nodes[Nodes[src_nid].Next_AC].IncomingQueue_AC[Nodes[Nodes[src_nid].Next_AC].TailPointer_AC] := msg_to_send;
        Nodes[Nodes[src_nid].Next_AC].TailPointer_AC := Nodes[Nodes[src_nid].Next_AC].TailPointer_AC + 1;
    else
        if Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].src_hops = 1 then
            msg_to_send.msg_type := response;
        else
            msg_to_send.msg_type := fwd_response;
        endif;

        msg_to_send.src_hops :=  Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].src_hops;
        msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].dest_hops;

        /* Shift messages in the source buffer */
        for i := 1 to Nodes[src_nid].TailPointer_AC - 1 do
            Nodes[src_nid].IncomingQueue_AC[i - 1] := Nodes[src_nid].IncomingQueue_AC[i];
        endfor;

        Nodes[src_nid].TailPointer_AC := Nodes[src_nid].TailPointer_AC - 1;
        Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].TailPointer_AC].msg_type := empty;

        Nodes[Nodes[src_nid].Next_CC].IncomingQueue_CC[Nodes[Nodes[src_nid].Next_CC].TailPointer_CC] := msg_to_send;
        Nodes[Nodes[src_nid].Next_CC].TailPointer_CC := Nodes[Nodes[src_nid].Next_CC].TailPointer_CC + 1;
    endif;
End;

Procedure ProcessFwdResponse(src_nid:NodeIDs; direction:0..1);
/*
src_nid --> node that is holding the incoming forwarded response
Process a forwarded response - 
 1. If the destination node id we have is not the final destination of the message
    then just pass the request along the chain.
 2. If it is the final destination, then pass a response and not a forwared response*/
   var msg_to_send: Message;
begin
    if direction = 0 then
        if Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].src_hops = 1 then
            msg_to_send.msg_type := response;
        else
            msg_to_send.msg_type := fwd_response;
        endif;

        msg_to_send.src_hops :=  Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].src_hops - 1;
        msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].FrontPointer].dest_hops;
    
        /* Shift messages in the source buffer */
        for i := 1 to Nodes[src_nid].TailPointer_CC - 1 do
            Nodes[src_nid].IncomingQueue_CC[i - 1] := Nodes[src_nid].IncomingQueue_CC[i];
        endfor;

        Nodes[src_nid].TailPointer_CC := Nodes[src_nid].TailPointer_CC - 1;
        Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].TailPointer_CC].msg_type := empty;

        Nodes[Nodes[src_nid].Next_CC].IncomingQueue_CC[Nodes[Nodes[src_nid].Next_CC].TailPointer_CC] := msg_to_send;
        Nodes[Nodes[src_nid].Next_CC].TailPointer_CC := Nodes[Nodes[src_nid].Next_CC].TailPointer_CC + 1;
    else
        if Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].src_hops = 1 then
            msg_to_send.msg_type := response;
        else
            msg_to_send.msg_type := fwd_response;
        endif;

        msg_to_send.src_hops :=  Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].src_hops - 1;
        msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].FrontPointer].dest_hops;
    
        /* Shift messages in the source buffer */
        for i := 1 to Nodes[src_nid].TailPointer_AC - 1 do
            Nodes[src_nid].IncomingQueue_AC[i - 1] := Nodes[src_nid].IncomingQueue_AC[i];
        endfor;

        Nodes[src_nid].TailPointer_AC := Nodes[src_nid].TailPointer_AC - 1;
        Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].TailPointer_AC].msg_type := empty;

        Nodes[Nodes[src_nid].Next_AC].IncomingQueue_AC[Nodes[Nodes[src_nid].Next_AC].TailPointer_AC] := msg_to_send;
        Nodes[Nodes[src_nid].Next_AC].TailPointer_AC := Nodes[Nodes[src_nid].Next_AC].TailPointer_AC + 1;
    endif;
End;

Procedure ProcessResponse(src_nid:NodeIDs; direction:0..1);
begin
    /*Process the response and free up the space.
    Shift everything to the right space by 1.*/
    if direction = 0 then
        for i: 1..BufferSpace-1 do
            Nodes[src_nid].IncomingQueue_CC[i - 1] := Nodes[src_nid].IncomingQueue_CC[i];
            Nodes[src_nid].IncomingQueue_CC[i].msg_type := empty;
        endfor;
        Nodes[src_nid].IncomingQueue_CC[Nodes[src_nid].TailPointer_CC - 1].msg_type := empty;
        Nodes[src_nid].TailPointer_CC := Nodes[src_nid].TailPointer_CC - 1;
    else
        for i: 1..BufferSpace-1 do
            Nodes[src_nid].IncomingQueue_AC[i - 1] := Nodes[src_nid].IncomingQueue_AC[i];
            Nodes[src_nid].IncomingQueue_AC[i].msg_type := empty;
        endfor;
        Nodes[src_nid].IncomingQueue_AC[Nodes[src_nid].TailPointer_AC - 1].msg_type := empty;
        Nodes[src_nid].TailPointer_AC := Nodes[src_nid].TailPointer_AC - 1;
    endif;
End;

Function GetNextNode(a: NodeIDs): NodeIDs;
Var
    found: Boolean;
    next: NodeIDs;
Begin
    found := false;
    /*Iterate over NodeIDs */
    For i: NodeIDs Do
        if found then
            return i;
        endif;
        if i = a then
            found := true;
        endif;
    Endfor;
    For i: NodeIDs Do
        return i;
    Endfor;
End;

Function GetPrevNode(a: NodeIDs): NodeIDs;
Var
    prev: NodeIDs;
    first: Boolean;
Begin
    first := true;
    For i: NodeIDs Do
        if i = a then
            if first then
                For j: NodeIDs Do
                    prev := j;
                Endfor;
                return prev;
            else
                return prev;
            endif;
        endif;
        prev := i;
        first := false;
    Endfor;
End;

/*Defining the start state here*/
StartState
Begin
    for nid1: NodeIDs do
            for s:0..BufferSpace-1 do
                Nodes[nid1].IncomingQueue_CC[s].msg_type := empty;
                Nodes[nid1].IncomingQueue_CC[s].src_hops := 0;
                Nodes[nid1].IncomingQueue_CC[s].dest_hops := 0;

                Nodes[nid1].IncomingQueue_AC[s].msg_type := empty;
                Nodes[nid1].IncomingQueue_AC[s].src_hops := 0;
                Nodes[nid1].IncomingQueue_AC[s].dest_hops := 0;
            endfor;
            Nodes[nid1].TailPointer_AC := 0; /* first insertion will be at the head of the queue */
            Nodes[nid1].TailPointer_CC := 0;
            Nodes[nid1].FrontPointer := 0;
            Nodes[nid1].Next_CC := GetNextNode(nid1);
            Nodes[nid1].Next_AC := GetPrevNode(nid1);
    endfor;
end;

ruleset n1: NodeIDs do
        ruleset n2: 1..2 do
            rule "Rule --> Send request 0"
                (Nodes[Nodes[n1].Next_CC].TailPointer_CC < BufferSpace)
            ==>
            Begin
                SendRequest(n1, n2, 0);
            endrule;


            rule "Rule --> Send request 1"
                (Nodes[Nodes[n1].Next_AC].TailPointer_AC < BufferSpace)
            ==>
            Begin
                SendRequest(n1, n2, 1);
            endrule;
    endruleset;
endruleset;

invariant "No 2-node Deadlock Cycles"
    forall n: NodeIDs do
        !(Nodes[n].TailPointer_CC = BufferSpace & Nodes[Nodes[n].Next_CC].TailPointer_CC = BufferSpace &
          Nodes[Nodes[n].Next_AC].TailPointer_AC = BufferSpace & Nodes[Nodes[Nodes[n].Next_CC].Next_AC].TailPointer_AC = BufferSpace)
    endforall;

invariant "No 3-node Deadlock Cycles"
    forall n: NodeIDs do
        !(Nodes[n].TailPointer_CC = BufferSpace & Nodes[Nodes[n].Next_CC].TailPointer_CC = BufferSpace &
          Nodes[Nodes[Nodes[n].Next_CC].Next_CC].TailPointer_CC = BufferSpace &
          Nodes[Nodes[Nodes[n].Next_CC].Next_AC].TailPointer_AC = BufferSpace &
          Nodes[Nodes[n].Next_AC].TailPointer_AC = BufferSpace & Nodes[Nodes[n].Next_CC].TailPointer_AC = BufferSpace)
    endforall;

invariant "No Global Deadlock (4-Node Cycle)"
    forall n: NodeIDs do
        !(forall m: NodeIDs do Nodes[m].TailPointer_CC = BufferSpace endforall |
          forall m: NodeIDs do Nodes[m].TailPointer_AC = BufferSpace endforall)
    endforall;