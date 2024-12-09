/*Defining the macros here*/
const
  NumberNodes: 3;
  BufferSpace: 3;

Type 
    MessageState: enum {empty, response, request, fwd_request, fwd_response};
    NodeIDs: scalarset(NumberNodes); 

Message: Record
    msg_type: MessageState;
    dest_hops: 0..NumberNodes;     /*Hops left to the destination - decrement this as you move along*/
    src_hops: 0..NumberNodes;       /*Hops left to the source - increment this as you move along*/
    End;

/*Making a node in here*/
Node: Record
    IncomingQueue: array[0..BufferSpace-1] of Message;
    TailPointer: 0..BufferSpace;
    FrontPointer: 0..1;
    Next: NodeIDs;
End;

var 
    Nodes: array[NodeIDs] of Node;

procedure SendRequest(src_nid:NodeIDs; next_hop_length:1..NumberNodes);
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

    msg_to_send.src_hops := NumberNodes - 1; /*Keep decreasing this as you go along*/
    msg_to_send.dest_hops := next_hop_length - 1; /*How far it needs to travel*/

    /*Add this message to the destination buffer*/
    Nodes[Nodes[src_nid].Next].IncomingQueue[Nodes[Nodes[src_nid].Next].TailPointer] := msg_to_send;
    Nodes[Nodes[src_nid].Next].TailPointer := Nodes[Nodes[src_nid].Next].TailPointer + 1;
end;


Procedure ProcessFwdRequest(src_nid:NodeIDs);
/*
src_nid --> source node that is currently holding the fwd_request message
Process a forwarded request - 
 1. If the destination node id we have is not the final destination of the message
    then just pass the request along the chain.
 2. If it is the final destination, then pass a request and not a forwared request*/
   var msg_to_send: Message;
begin
    if  Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].dest_hops = 1 then
        msg_to_send.msg_type := request; /*Send a request because the next hop is the actual destination*/
    else
        msg_to_send.msg_type := fwd_request; /*Send a fwd_request because the next hop is not the actual destination*/
    endif; 
    /*Decrease both the destination hop and the source hop count*/
    msg_to_send.src_hops := Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].src_hops - 1;
    msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].dest_hops - 1;
  
   /* Shift messages in the source buffer */
    for i := 1 to Nodes[src_nid].TailPointer - 1 do
        Nodes[src_nid].IncomingQueue[i - 1] := Nodes[src_nid].IncomingQueue[i];
    endfor;

    Nodes[src_nid].TailPointer := Nodes[src_nid].TailPointer - 1;
    Nodes[src_nid].IncomingQueue[Nodes[src_nid].TailPointer].msg_type := empty;

    Nodes[Nodes[src_nid].Next].IncomingQueue[Nodes[Nodes[src_nid].Next].TailPointer] := msg_to_send;
    Nodes[Nodes[src_nid].Next].TailPointer := Nodes[Nodes[src_nid].Next].TailPointer + 1;
End;

Procedure ProcessRequest(src_nid: NodeIDs);
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
    if Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].src_hops = 1 then
        msg_to_send.msg_type := response;
    else
        msg_to_send.msg_type := fwd_response;
    endif;

    msg_to_send.src_hops :=  Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].src_hops - 1;
    msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].dest_hops;

    /* Shift messages in the source buffer */
    for i := 1 to Nodes[src_nid].TailPointer - 1 do
        Nodes[src_nid].IncomingQueue[i - 1] := Nodes[src_nid].IncomingQueue[i];
    endfor;

    Nodes[src_nid].TailPointer := Nodes[src_nid].TailPointer - 1;
    Nodes[src_nid].IncomingQueue[Nodes[src_nid].TailPointer].msg_type := empty;

    Nodes[Nodes[src_nid].Next].IncomingQueue[Nodes[Nodes[src_nid].Next].TailPointer] := msg_to_send;
    Nodes[Nodes[src_nid].Next].TailPointer := Nodes[Nodes[src_nid].Next].TailPointer + 1;
End;

Procedure ProcessFwdResponse(src_nid:NodeIDs);
/*
src_nid --> node that is holding the incoming forwarded response
Process a forwarded response - 
 1. If the destination node id we have is not the final destination of the message
    then just pass the request along the chain.
 2. If it is the final destination, then pass a response and not a forwared response*/
   var msg_to_send: Message;
begin
    if Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].src_hops = 1 then
        msg_to_send.msg_type := response;
    else
        msg_to_send.msg_type := fwd_response;
    endif;

    msg_to_send.src_hops :=  Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].src_hops - 1;
    msg_to_send.dest_hops := Nodes[src_nid].IncomingQueue[Nodes[src_nid].FrontPointer].dest_hops;
  
   /* Shift messages in the source buffer */
    for i := 1 to Nodes[src_nid].TailPointer - 1 do
        Nodes[src_nid].IncomingQueue[i - 1] := Nodes[src_nid].IncomingQueue[i];
    endfor;

    Nodes[src_nid].TailPointer := Nodes[src_nid].TailPointer - 1;
    Nodes[src_nid].IncomingQueue[Nodes[src_nid].TailPointer].msg_type := empty;

    Nodes[Nodes[src_nid].Next].IncomingQueue[Nodes[Nodes[src_nid].Next].TailPointer] := msg_to_send;
    Nodes[Nodes[src_nid].Next].TailPointer := Nodes[Nodes[src_nid].Next].TailPointer + 1;
End;

Procedure ProcessResponse(src_nid:NodeIDs);
begin
    /*Process the response and free up the space.
    Shift everything to the right space by 1.*/
  for i: 1..BufferSpace-1 do
    Nodes[src_nid].IncomingQueue[i - 1] := Nodes[src_nid].IncomingQueue[i];
    Nodes[src_nid].IncomingQueue[i].msg_type := empty;
  endfor;
  Nodes[src_nid].IncomingQueue[Nodes[src_nid].TailPointer - 1].msg_type := empty;
  Nodes[src_nid].TailPointer := Nodes[src_nid].TailPointer - 1;
End;

Function GetNextNode(a: NodeIDs): NodeIDs;
Var
    found: Boolean;
    next: NodeIDs;
Begin
    found := false;
    -- Iterate over NodeIDs
    For i: NodeIDs Do
        if found then
            -- Return the next node after 'a'
            return i;
        endif;
        if i = a then
            found := true; -- Mark that we've found 'a'
        endif;
    Endfor;
    For i: NodeIDs Do
        return i;
    Endfor;
End;

/*Defining the start state here*/
StartState
Begin
    for nid1: NodeIDs do
            for s:0..BufferSpace-1 do
                Nodes[nid1].IncomingQueue[s].msg_type := empty;
                Nodes[nid1].IncomingQueue[s].src_hops := 0;
                Nodes[nid1].IncomingQueue[s].dest_hops := 0;
            endfor;
            Nodes[nid1].TailPointer := 0; /* first insertion will be at the head of the queue */
            Nodes[nid1].FrontPointer := 0;
            Nodes[nid1].Next := GetNextNode(nid1);
    endfor;

end;

ruleset n1: NodeIDs do
        rule "Rule --> Process request"
            (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace)
        ==>
        Begin
            ProcessRequest(n1);
        endrule;
endruleset;


ruleset n1: NodeIDs do
        rule "Rule --> Process fwd_request"
            (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace)
        ==>
        Begin
            ProcessFwdRequest(n1);
        endrule;
endruleset;


ruleset n1: NodeIDs do
        rule "Rule --> Process response"
            (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = response)
        ==>
        Begin
            ProcessResponse(n1);
        endrule;
endruleset;


ruleset n1: NodeIDs do
        rule "Rule --> Process fwd_response"
            (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace)
        ==>
        Begin
            ProcessFwdResponse(n1);
        endrule;
endruleset;


ruleset n1: NodeIDs do
        ruleset n2: 1..NumberNodes-1 do
            rule "Rule --> Send request"
                (Nodes[Nodes[n1].Next].TailPointer < BufferSpace - 1)
            ==>
            Begin
                SendRequest(n1, n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process request + Process response"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                (n1 != n2)
            ==>
            Begin
                ProcessRequest(n1);
                ProcessResponse(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process fwd_request + Process fwd_request"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdRequest(n1);
                ProcessFwdRequest(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: 1..NumberNodes-1 do
                rule "Rule --> Process request + Send request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[Nodes[n2].Next].TailPointer < BufferSpace - 1) & 
                    (n1 != n2)
                ==>
                Begin
                    ProcessRequest(n1);
                    SendRequest(n2, n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process fwd_request + Process response"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdRequest(n1);
                ProcessResponse(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process fwd_response + Process response"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdResponse(n1);
                ProcessResponse(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process request + Process request"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                (n1 != n2)
            ==>
            Begin
                ProcessRequest(n1);
                ProcessRequest(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process fwd_request + Process fwd_response"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdRequest(n1);
                ProcessFwdResponse(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process fwd_response + Process fwd_response"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdResponse(n1);
                ProcessFwdResponse(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
        ruleset n2: 1..NumberNodes-1 do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Send request + Send request"
                        (Nodes[Nodes[n1].Next].TailPointer < BufferSpace - 1) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n3)
                    ==>
                    Begin
                        SendRequest(n1, n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: 1..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Send request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[Nodes[n2].Next].TailPointer < BufferSpace - 1) & 
                    (n1 != n2)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    SendRequest(n2, n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: 1..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Send request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[Nodes[n2].Next].TailPointer < BufferSpace - 1) & 
                    (n1 != n2)
                ==>
                Begin
                    ProcessFwdResponse(n1);
                    SendRequest(n2, n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process fwd_request + Process request"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdRequest(n1);
                ProcessRequest(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process response + Process response"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = response) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                (n1 != n2)
            ==>
            Begin
                ProcessResponse(n1);
                ProcessResponse(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
            rule "Rule --> Process fwd_response + Process request"
                (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdResponse(n1);
                ProcessRequest(n2);
            endrule;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: 1..NumberNodes-1 do
                rule "Rule --> Process response + Send request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = response) & 
                    (Nodes[Nodes[n2].Next].TailPointer < BufferSpace - 1) & 
                    (n1 != n2)
                ==>
                Begin
                    ProcessResponse(n1);
                    SendRequest(n2, n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process response + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessFwdResponse(n1);
                        ProcessResponse(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: 1..NumberNodes-1 do
            ruleset n4: NodeIDs do
        ruleset n5: 1..NumberNodes-1 do
                        rule "Rule --> Process request + Send request + Send request"
                            (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                            (Nodes[Nodes[n2].Next].TailPointer < BufferSpace - 1) & 
                            (Nodes[Nodes[n4].Next].TailPointer < BufferSpace - 1) & 
                            (n1 != n2) & 
                            (n1 != n4) & 
                            (n2 != n4)
                        ==>
                        Begin
                            ProcessRequest(n1);
                            SendRequest(n2, n3);
                            SendRequest(n4, n5);
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process response + Process response + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = response) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessResponse(n1);
                        ProcessResponse(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process request + Process response + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1);
                    ProcessResponse(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process request + Process request + Process request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = request) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1);
                    ProcessRequest(n2);
                    ProcessRequest(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process request + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessFwdRequest(n1);
                        ProcessRequest(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process fwd_request + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessFwdRequest(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process request + Process request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = request) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessRequest(n2);
                    ProcessRequest(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process request + Process response + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessRequest(n1);
                        ProcessResponse(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process request + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessRequest(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process fwd_request + Process fwd_response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessFwdRequest(n2);
                    ProcessFwdResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: 1..NumberNodes-1 do
            ruleset n4: NodeIDs do
        ruleset n5: 1..NumberNodes-1 do
                        rule "Rule --> Process fwd_request + Send request + Send request"
                            (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                            (Nodes[Nodes[n2].Next].TailPointer < BufferSpace - 1) & 
                            (Nodes[Nodes[n4].Next].TailPointer < BufferSpace - 1) & 
                            (n1 != n2) & 
                            (n1 != n4) & 
                            (n2 != n4)
                        ==>
                        Begin
                            ProcessFwdRequest(n1);
                            SendRequest(n2, n3);
                            SendRequest(n4, n5);
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process response + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessResponse(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process fwd_response + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessFwdResponse(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_response + Process request + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1);
                    ProcessRequest(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_request + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessFwdRequest(n1);
                        ProcessFwdRequest(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process fwd_request + Process request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = request) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessFwdRequest(n2);
                    ProcessRequest(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process fwd_response + Process fwd_response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessFwdResponse(n2);
                    ProcessFwdResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process response + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessFwdRequest(n1);
                        ProcessResponse(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_response + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessFwdRequest(n1);
                        ProcessFwdResponse(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
        ruleset n2: 1..NumberNodes-1 do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                ruleset n5: NodeIDs do
        ruleset n6: 1..NumberNodes-1 do
                            rule "Rule --> Send request + Send request + Send request"
                                (Nodes[Nodes[n1].Next].TailPointer < BufferSpace - 1) & 
                                (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                                (Nodes[Nodes[n5].Next].TailPointer < BufferSpace - 1) & 
                                (n1 != n3) & 
                                (n1 != n5) & 
                                (n3 != n5)
                            ==>
                            Begin
                                SendRequest(n1, n2);
                                SendRequest(n3, n4);
                                SendRequest(n5, n6);
                            endrule;
                    endruleset;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process request + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessFwdResponse(n1);
                        ProcessRequest(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_response + Process fwd_response + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1);
                    ProcessFwdResponse(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process fwd_response + Process request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = request) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessFwdResponse(n2);
                    ProcessRequest(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: 1..NumberNodes-1 do
            ruleset n4: NodeIDs do
        ruleset n5: 1..NumberNodes-1 do
                        rule "Rule --> Process fwd_response + Send request + Send request"
                            (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                            (Nodes[Nodes[n2].Next].TailPointer < BufferSpace - 1) & 
                            (Nodes[Nodes[n4].Next].TailPointer < BufferSpace - 1) & 
                            (n1 != n2) & 
                            (n1 != n4) & 
                            (n2 != n4)
                        ==>
                        Begin
                            ProcessFwdResponse(n1);
                            SendRequest(n2, n3);
                            SendRequest(n4, n5);
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: 1..NumberNodes-1 do
            ruleset n4: NodeIDs do
        ruleset n5: 1..NumberNodes-1 do
                        rule "Rule --> Process response + Send request + Send request"
                            (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = response) & 
                            (Nodes[Nodes[n2].Next].TailPointer < BufferSpace - 1) & 
                            (Nodes[Nodes[n4].Next].TailPointer < BufferSpace - 1) & 
                            (n1 != n2) & 
                            (n1 != n4) & 
                            (n2 != n4)
                        ==>
                        Begin
                            ProcessResponse(n1);
                            SendRequest(n2, n3);
                            SendRequest(n4, n5);
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_response + Process request + Process request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = request) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1);
                    ProcessRequest(n2);
                    ProcessRequest(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_response + Process fwd_response + Process fwd_response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1);
                    ProcessFwdResponse(n2);
                    ProcessFwdResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process request + Process request + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1);
                    ProcessRequest(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_response + Process response + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1);
                    ProcessResponse(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process fwd_response + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessFwdResponse(n1);
                        ProcessFwdResponse(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process response + Process response + Process response"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = response) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = response) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = response) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessResponse(n1);
                    ProcessResponse(n2);
                    ProcessResponse(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_request + Process fwd_request + Process fwd_request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = fwd_request) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1);
                    ProcessFwdRequest(n2);
                    ProcessFwdRequest(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
                rule "Rule --> Process fwd_response + Process fwd_response + Process request"
                    (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                    (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = fwd_response) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                    (Nodes[n3].IncomingQueue[Nodes[n3].FrontPointer].msg_type = request) & (Nodes[Nodes[n3].Next].TailPointer < BufferSpace) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1);
                    ProcessFwdResponse(n2);
                    ProcessRequest(n3);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: NodeIDs do
    ruleset n2: NodeIDs do
        ruleset n3: NodeIDs do
        ruleset n4: 1..NumberNodes-1 do
                    rule "Rule --> Process request + Process request + Send request"
                        (Nodes[n1].IncomingQueue[Nodes[n1].FrontPointer].msg_type = request) & (Nodes[Nodes[n1].Next].TailPointer < BufferSpace) & 
                        (Nodes[n2].IncomingQueue[Nodes[n2].FrontPointer].msg_type = request) & (Nodes[Nodes[n2].Next].TailPointer < BufferSpace) & 
                        (Nodes[Nodes[n3].Next].TailPointer < BufferSpace - 1) & 
                        (n1 != n2) & 
                        (n1 != n3) & 
                        (n2 != n3)
                    ==>
                    Begin
                        ProcessRequest(n1);
                        ProcessRequest(n2);
                        SendRequest(n3, n4);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;
