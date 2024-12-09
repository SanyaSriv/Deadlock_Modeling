/*Defining the macros here*/
const
  NumberNodes: 3;
  BufferSpace: 3;
  

type MessageState: enum {empty, response, request, fwd_request, fwd_response};

/*Defining the node IDs here*/
type NodeIDs: 0..NumberNodes-1; 

Message: Record
    msg_type: MessageState;
    dest_nid: NodeIDs;
    src_nid: NodeIDs
    End;

type Queue: array[0..BufferSpace-1] of Message;
/*IncomingQueue[i][j] := incoming link of node i that connects node j
So, it will recieve all the messages node j sends i.*/
var IncomingQueue: array[NodeIDs] of array[NodeIDs] of Queue;
/*To track position of next message insertion in the queue*/
var TailPointers: array[NodeIDs] of array[NodeIDs] of 0..BufferSpace;
/*Array to indicate a node's router status
1 = Node is a router | 0 = Node is not a router*/
var RouterStatus: array[0..NumberNodes] of 0..1;
var IntentToSendRequest: array[NodeIDs] of 0..2;

var ExitPath: array[NodeIDs] of NodeIDs;
var EntryPath: array[NodeIDs] of NodeIDs;

procedure SendRequest(src_nid:NodeIDs; next_hop:NodeIDs; msg_dest:NodeIDs);
    /*Send a request -
    src_nid --> source node that is sending the request
    msg_dest --> actual destination node for the message
    next_hop --> node that the source node is connected to and needs to pass the message to.
    1. If the actual destination of the message is the next hop, then send a request.
    2. If the next hop is not the final destination, send a forwarded request.
    The message should always have the original source and destination. */
    var msg_to_send: Message;
begin
    if next_hop = msg_dest then
        msg_to_send.msg_type := request; /*Send a request*/
    else
        msg_to_send.msg_type := fwd_request; /*Send a forwarded request*/
    endif;

    msg_to_send.src_nid := src_nid;
    msg_to_send.dest_nid := msg_dest; /*Original destination*/

    /*Add this message to the destination buffer*/
    IncomingQueue[next_hop][src_nid][TailPointers[next_hop][src_nid]] := msg_to_send;
    TailPointers[next_hop][src_nid] := TailPointers[next_hop][src_nid] + 1;
end;

Procedure ProcessFwdRequest(src_nid:NodeIDs; incom_to_src_nid:NodeIDs; next_hop:NodeIDs);
/*
Topology structure in this case: incom_to_src_nid --> src_nid --> next_hop
src_nid --> source node that is currently holding the fwd_request message
incom_to_src_nid --> node from which this node recieved the message
next_hop --> node that the source node is connected to and needs to pass the message to.
Process a forwarded request - 
 1. If the destination node id we have is not the final destination of the message
    then just pass the request along the chain.
 2. If it is the final destination, then pass a request and not a forwared request*/
   var msg_to_send: Message;
begin
    if IncomingQueue[src_nid][incom_to_src_nid][0].dest_nid = next_hop then
        msg_to_send.msg_type := request; /*Send a request because the next hop is the actual destination*/
    else
        msg_to_send.msg_type := fwd_request; /*Send a fwd_request because the next hop is not the actual destination*/
    endif; 
    /*Rest of the source and destination should be the original message's*/
    msg_to_send.src_nid := IncomingQueue[src_nid][incom_to_src_nid][0].src_nid;
    msg_to_send.dest_nid := IncomingQueue[src_nid][incom_to_src_nid][0].dest_nid;
  
   /* Shift messages in the source buffer */
    for i := 1 to TailPointers[src_nid][incom_to_src_nid] - 1 do
        IncomingQueue[src_nid][incom_to_src_nid][i - 1] := IncomingQueue[src_nid][incom_to_src_nid][i];
    endfor;

    TailPointers[src_nid][incom_to_src_nid] := TailPointers[src_nid][incom_to_src_nid] - 1;
    IncomingQueue[src_nid][incom_to_src_nid][TailPointers[src_nid][incom_to_src_nid]].msg_type := empty;
    /*Send the message forward*/
    /* Add the request/fwd_request message to the next hop buffer */
    IncomingQueue[next_hop][src_nid][TailPointers[next_hop][src_nid]] := msg_to_send;
    /* Update the tail pointer for the destination buffer */
    TailPointers[next_hop][src_nid] := TailPointers[next_hop][src_nid] + 1;
End;

Procedure ProcessRequest(src_nid: NodeIDs; incom_to_src_nid: NodeIDs; next_hop:NodeIDs);
    /*
    src_nid --> node that is holding the incoming request
    incom_to_src_node --> node that initially sent/forwarded the request to src
    next_hop --> the node to which src_node would sent the request
    Process a request -
    1. If this is a request, then it implies the message is already at its destination
       so we either need to send a response or a forwarded response based on whether
       the original destination is the next hop.
    */
  
  /*Make the response message that should be sent*/
   var msg_to_send: Message;
Begin
    if IncomingQueue[src_nid][incom_to_src_nid][0].src_nid = next_hop then
        msg_to_send.msg_type := response;
    else
        msg_to_send.msg_type := fwd_response;
    endif;
    msg_to_send.src_nid :=  IncomingQueue[src_nid][incom_to_src_nid][0].dest_nid; /*Message is travelling back - so dest becomes source*/
    msg_to_send.dest_nid := IncomingQueue[src_nid][incom_to_src_nid][0].src_nid; /*Message is travalling bak - so source becomes dest */

    /* Shift messages in the source buffer */
    for i := 1 to TailPointers[src_nid][incom_to_src_nid] - 1 do
        IncomingQueue[src_nid][incom_to_src_nid][i - 1] := IncomingQueue[src_nid][incom_to_src_nid][i];
    endfor;

    TailPointers[src_nid][incom_to_src_nid] := TailPointers[src_nid][incom_to_src_nid] - 1;
    IncomingQueue[src_nid][incom_to_src_nid][TailPointers[src_nid][incom_to_src_nid]].msg_type := empty;

    /* Add the response message to the destination buffer */
    IncomingQueue[next_hop][src_nid][TailPointers[next_hop][src_nid]] := msg_to_send;
    /* Update the tail pointer for the destination buffer */
    TailPointers[next_hop][src_nid] := TailPointers[next_hop][src_nid] + 1;
End;

Procedure ProcessFwdResponse(src_nid:NodeIDs; incom_to_src_nid:NodeIDs; next_hop:NodeIDs);
/*
src_nid --> node that is holding the incoming forwarded response
incom_to_src_node --> node that initially sent/forwarded the response to src
next_hop --> the node to which src_node would sent the response to
In this procedure, src_nid is the node that is currently holding the forwarded response in its buffer. 
It is not the node that originated the request.
Process a forwarded response - 
 1. If the destination node id we have is not the final destination of the message
    then just pass the request along the chain.
 2. If it is the final destination, then pass a response and not a forwared response*/
   var msg_to_send: Message;
begin
    if IncomingQueue[src_nid][incom_to_src_nid][0].dest_nid = next_hop then
        msg_to_send.msg_type := response; /*Send a response because the next hop is the actual destination*/
    else
        msg_to_send.msg_type := fwd_response; /*Send a fwd_response because the next hop is not the actual destination*/
    endif; 
    /*Rest of the source and destination should be the original message's*/
    msg_to_send.src_nid := IncomingQueue[src_nid][incom_to_src_nid][0].src_nid;
    msg_to_send.dest_nid := IncomingQueue[src_nid][incom_to_src_nid][0].dest_nid;
  
   /* Shift messages in the source buffer */
    for i := 1 to TailPointers[src_nid][incom_to_src_nid] - 1 do
        IncomingQueue[src_nid][incom_to_src_nid][i - 1] := IncomingQueue[src_nid][incom_to_src_nid][i];
    endfor;

    TailPointers[src_nid][incom_to_src_nid] := TailPointers[src_nid][incom_to_src_nid] - 1;
    IncomingQueue[src_nid][incom_to_src_nid][TailPointers[src_nid][incom_to_src_nid]].msg_type := empty;

  /*Send the message forward*/
  /* Add the response/fwd_response message to the next hop buffer */
  IncomingQueue[next_hop][src_nid][TailPointers[next_hop][src_nid]] := msg_to_send;
  /* Update the tail pointer for the destination buffer */
  TailPointers[next_hop][src_nid] := TailPointers[next_hop][src_nid] + 1;
End;

Procedure ProcessResponse(src_nid:NodeIDs; incom_to_src_nid:NodeIDs);
begin
    /*Process the response and free up the space.
    Shift everything to the right space by 1.*/
  for i: 1..BufferSpace-1 do
    IncomingQueue[src_nid][incom_to_src_nid][i - 1] := IncomingQueue[src_nid][incom_to_src_nid][i];
    IncomingQueue[src_nid][incom_to_src_nid][i].msg_type := empty; /*Reset the space shifted*/
  endfor;
  IncomingQueue[src_nid][incom_to_src_nid][TailPointers[src_nid][incom_to_src_nid] - 1].msg_type := empty;
  TailPointers[src_nid][incom_to_src_nid] := TailPointers[src_nid][incom_to_src_nid] - 1;
End;

/*Defining the start state here*/
StartState
Begin
    for nid1:0..NumberNodes-1 do
        for nid2:0..NumberNodes-1 do
            for s:0..BufferSpace-1 do
                IncomingQueue[nid1][nid2][s].msg_type := empty;
            endfor;
        TailPointers[nid1][nid2] := 0; /* first insertion will be at the head of the queue */
        endfor;
    endfor;

    for nid:0..NumberNodes-1 do
        if (nid != NumberNodes-1) then
            ExitPath[nid] := nid+1; /*nid --> nid + 1*/ 
            if nid = 0 then
                EntryPath[nid] := NumberNodes-1;
            else
                EntryPath[nid] := nid - 1;
            endif;
        else
            ExitPath[nid] := 0; /*NumberNodes-1 ---> node 0*/
            EntryPath[nid] := nid - 1;
        endif;
    endfor;

        for n1: 0..NumberNodes-1 do
    IntentToSendRequest[n1] := 0;
    endfor;
end;

ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Send request"
                (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2)
            ==>
            Begin
                if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                SendRequest(n1, ExitPath[n1], n2);
                IntentToSendRequest[n1] := 0;
            else
                IntentToSendRequest[n1] := 2;
            endif;
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
        rule "Rule --> Process fwd_request"
            (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1)
        ==>
        Begin
            ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
        endrule;
endruleset;


ruleset n1: 0..NumberNodes-1 do
        rule "Rule --> Process request"
            (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1)
        ==>
        Begin
            ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
        endrule;
endruleset;


ruleset n1: 0..NumberNodes-1 do
        rule "Rule --> Process fwd_response"
            (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1)
        ==>
        Begin
            ProcessFwdResponse(n1, EntryPath[n1], ExitPath[n1]);
        endrule;
endruleset;


ruleset n1: 0..NumberNodes-1 do
        rule "Rule --> Process response"
            (IncomingQueue[n1][EntryPath[n1]][0].msg_type = response) & (IntentToSendRequest[n1] != 1)
        ==>
        Begin
            ProcessResponse(n1, EntryPath[n1]);
        if IntentToSendRequest[n1] = 2 then
            IntentToSendRequest[n1] := 1
        endif;
        endrule;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Send request"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (n3 != n4) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 2) & 
                        (n1 != n3)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        if ((IntentToSendRequest[n3] = 1) | (TailPointers[n3][EntryPath[n3]] = 0)) then
                        SendRequest(n3, ExitPath[n3], n4);
                        IntentToSendRequest[n3] := 0;
                    else
                        IntentToSendRequest[n3] := 2;
                    endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Send request + Process fwd_request"
                    (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n3)
                ==>
                Begin
                    if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                    SendRequest(n1, ExitPath[n1], n2);
                    IntentToSendRequest[n1] := 0;
                else
                    IntentToSendRequest[n1] := 2;
                endif;
                    ProcessFwdRequest(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Send request + Process request"
                    (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n3)
                ==>
                Begin
                    if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                    SendRequest(n1, ExitPath[n1], n2);
                    IntentToSendRequest[n1] := 0;
                else
                    IntentToSendRequest[n1] := 2;
                endif;
                    ProcessRequest(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Send request + Process fwd_response"
                    (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n3)
                ==>
                Begin
                    if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                    SendRequest(n1, ExitPath[n1], n2);
                    IntentToSendRequest[n1] := 0;
                else
                    IntentToSendRequest[n1] := 2;
                endif;
                    ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Send request + Process response"
                    (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n3)
                ==>
                Begin
                    if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                    SendRequest(n1, ExitPath[n1], n2);
                    IntentToSendRequest[n1] := 0;
                else
                    IntentToSendRequest[n1] := 2;
                endif;
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_request + Process fwd_request"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                ProcessFwdRequest(n2, EntryPath[n2], ExitPath[n2]);
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_request + Process request"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                ProcessRequest(n2, EntryPath[n2], ExitPath[n2]);
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_request + Process fwd_response"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_request + Process response"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = response) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                ProcessResponse(n2, EntryPath[n2]);
            if IntentToSendRequest[n2] = 2 then
                IntentToSendRequest[n2] := 1
            endif;
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process request + Process request"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                ProcessRequest(n2, EntryPath[n2], ExitPath[n2]);
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process request + Process fwd_response"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process request + Process response"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = response) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                ProcessResponse(n2, EntryPath[n2]);
            if IntentToSendRequest[n2] = 2 then
                IntentToSendRequest[n2] := 1
            endif;
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_response + Process fwd_response"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdResponse(n1, EntryPath[n1], ExitPath[n1]);
                ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_response + Process response"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = response) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessFwdResponse(n1, EntryPath[n1], ExitPath[n1]);
                ProcessResponse(n2, EntryPath[n2]);
            if IntentToSendRequest[n2] = 2 then
                IntentToSendRequest[n2] := 1
            endif;
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
            rule "Rule --> Process response + Process response"
                (IncomingQueue[n1][EntryPath[n1]][0].msg_type = response) & (IntentToSendRequest[n1] != 1) & 
                (IncomingQueue[n2][EntryPath[n2]][0].msg_type = response) & (IntentToSendRequest[n2] != 1) & 
                (n1 != n2)
            ==>
            Begin
                ProcessResponse(n1, EntryPath[n1]);
            if IntentToSendRequest[n1] = 2 then
                IntentToSendRequest[n1] := 1
            endif;
                ProcessResponse(n2, EntryPath[n2]);
            if IntentToSendRequest[n2] = 2 then
                IntentToSendRequest[n2] := 1
            endif;
            endrule;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                ruleset n5: 0..NumberNodes-1 do
                    ruleset n6: 0..NumberNodes-1 do
                            rule "Rule --> Send request + Send request + Send request"
                                (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                                (n3 != n4) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 2) & 
                                (n5 != n6) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (IntentToSendRequest[n5] != 2) & 
                                (n1 != n3) & 
                                (n1 != n5) & 
                                (n3 != n5)
                            ==>
                            Begin
                                if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                                SendRequest(n1, ExitPath[n1], n2);
                                IntentToSendRequest[n1] := 0;
                            else
                                IntentToSendRequest[n1] := 2;
                            endif;
                                if ((IntentToSendRequest[n3] = 1) | (TailPointers[n3][EntryPath[n3]] = 0)) then
                                SendRequest(n3, ExitPath[n3], n4);
                                IntentToSendRequest[n3] := 0;
                            else
                                IntentToSendRequest[n3] := 2;
                            endif;
                                if ((IntentToSendRequest[n5] = 1) | (TailPointers[n5][EntryPath[n5]] = 0)) then
                                SendRequest(n5, ExitPath[n5], n6);
                                IntentToSendRequest[n5] := 0;
                            else
                                IntentToSendRequest[n5] := 2;
                            endif;
                            endrule;
                    endruleset;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                ruleset n5: 0..NumberNodes-1 do
                        rule "Rule --> Send request + Send request + Process fwd_request"
                            (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                            (n3 != n4) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 2) & 
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (IntentToSendRequest[n5] != 1) & 
                            (n1 != n3) & 
                            (n1 != n5) & 
                            (n3 != n5)
                        ==>
                        Begin
                            if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                            SendRequest(n1, ExitPath[n1], n2);
                            IntentToSendRequest[n1] := 0;
                        else
                            IntentToSendRequest[n1] := 2;
                        endif;
                            if ((IntentToSendRequest[n3] = 1) | (TailPointers[n3][EntryPath[n3]] = 0)) then
                            SendRequest(n3, ExitPath[n3], n4);
                            IntentToSendRequest[n3] := 0;
                        else
                            IntentToSendRequest[n3] := 2;
                        endif;
                            ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                ruleset n5: 0..NumberNodes-1 do
                        rule "Rule --> Send request + Send request + Process request"
                            (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                            (n3 != n4) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 2) & 
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (IntentToSendRequest[n5] != 1) & 
                            (n1 != n3) & 
                            (n1 != n5) & 
                            (n3 != n5)
                        ==>
                        Begin
                            if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                            SendRequest(n1, ExitPath[n1], n2);
                            IntentToSendRequest[n1] := 0;
                        else
                            IntentToSendRequest[n1] := 2;
                        endif;
                            if ((IntentToSendRequest[n3] = 1) | (TailPointers[n3][EntryPath[n3]] = 0)) then
                            SendRequest(n3, ExitPath[n3], n4);
                            IntentToSendRequest[n3] := 0;
                        else
                            IntentToSendRequest[n3] := 2;
                        endif;
                            ProcessRequest(n5, EntryPath[n5], ExitPath[n5]);
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                ruleset n5: 0..NumberNodes-1 do
                        rule "Rule --> Send request + Send request + Process fwd_response"
                            (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                            (n3 != n4) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 2) & 
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (IntentToSendRequest[n5] != 1) & 
                            (n1 != n3) & 
                            (n1 != n5) & 
                            (n3 != n5)
                        ==>
                        Begin
                            if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                            SendRequest(n1, ExitPath[n1], n2);
                            IntentToSendRequest[n1] := 0;
                        else
                            IntentToSendRequest[n1] := 2;
                        endif;
                            if ((IntentToSendRequest[n3] = 1) | (TailPointers[n3][EntryPath[n3]] = 0)) then
                            SendRequest(n3, ExitPath[n3], n4);
                            IntentToSendRequest[n3] := 0;
                        else
                            IntentToSendRequest[n3] := 2;
                        endif;
                            ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                ruleset n5: 0..NumberNodes-1 do
                        rule "Rule --> Send request + Send request + Process response"
                            (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                            (n3 != n4) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 2) & 
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = response) & (IntentToSendRequest[n5] != 1) & 
                            (n1 != n3) & 
                            (n1 != n5) & 
                            (n3 != n5)
                        ==>
                        Begin
                            if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                            SendRequest(n1, ExitPath[n1], n2);
                            IntentToSendRequest[n1] := 0;
                        else
                            IntentToSendRequest[n1] := 2;
                        endif;
                            if ((IntentToSendRequest[n3] = 1) | (TailPointers[n3][EntryPath[n3]] = 0)) then
                            SendRequest(n3, ExitPath[n3], n4);
                            IntentToSendRequest[n3] := 0;
                        else
                            IntentToSendRequest[n3] := 2;
                        endif;
                            ProcessResponse(n5, EntryPath[n5]);
                        if IntentToSendRequest[n5] = 2 then
                            IntentToSendRequest[n5] := 1
                        endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process fwd_request + Process fwd_request"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n4]][n4] < BufferSpace) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessFwdRequest(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessFwdRequest(n4, EntryPath[n4], ExitPath[n4]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process fwd_request + Process request"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = request) & (TailPointers[ExitPath[n4]][n4] < BufferSpace) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessFwdRequest(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessRequest(n4, EntryPath[n4], ExitPath[n4]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process fwd_request + Process fwd_response"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n4]][n4] < BufferSpace) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessFwdRequest(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessFwdResponse(n4, EntryPath[n4], ExitPath[n4]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process fwd_request + Process response"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = response) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessFwdRequest(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessResponse(n4, EntryPath[n4]);
                    if IntentToSendRequest[n4] = 2 then
                        IntentToSendRequest[n4] := 1
                    endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process request + Process request"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = request) & (TailPointers[ExitPath[n4]][n4] < BufferSpace) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessRequest(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessRequest(n4, EntryPath[n4], ExitPath[n4]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process request + Process fwd_response"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n4]][n4] < BufferSpace) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessRequest(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessFwdResponse(n4, EntryPath[n4], ExitPath[n4]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process request + Process response"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = response) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessRequest(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessResponse(n4, EntryPath[n4]);
                    if IntentToSendRequest[n4] = 2 then
                        IntentToSendRequest[n4] := 1
                    endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process fwd_response + Process fwd_response"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n4]][n4] < BufferSpace) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessFwdResponse(n4, EntryPath[n4], ExitPath[n4]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process fwd_response + Process response"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = response) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                        ProcessResponse(n4, EntryPath[n4]);
                    if IntentToSendRequest[n4] = 2 then
                        IntentToSendRequest[n4] := 1
                    endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
            ruleset n4: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Process response + Process response"
                        (n1 != n2) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 2) & 
                        (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                        (IncomingQueue[n4][EntryPath[n4]][0].msg_type = response) & (IntentToSendRequest[n4] != 1) & 
                        (n1 != n3) & 
                        (n1 != n4) & 
                        (n3 != n4)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n1] = 1) | (TailPointers[n1][EntryPath[n1]] = 0)) then
                        SendRequest(n1, ExitPath[n1], n2);
                        IntentToSendRequest[n1] := 0;
                    else
                        IntentToSendRequest[n1] := 2;
                    endif;
                        ProcessResponse(n3, EntryPath[n3]);
                    if IntentToSendRequest[n3] = 2 then
                        IntentToSendRequest[n3] := 1
                    endif;
                        ProcessResponse(n4, EntryPath[n4]);
                    if IntentToSendRequest[n4] = 2 then
                        IntentToSendRequest[n4] := 1
                    endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_request + Process fwd_request"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessFwdRequest(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_request + Process request"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessRequest(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_request + Process fwd_response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_request + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process request + Process request"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessRequest(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process request + Process fwd_response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process request + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_response + Process fwd_response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_response + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process response + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = response) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessResponse(n2, EntryPath[n2]);
                if IntentToSendRequest[n2] = 2 then
                    IntentToSendRequest[n2] := 1
                endif;
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process request + Process request + Process request"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = request) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessRequest(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process request + Process request + Process fwd_response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process request + Process request + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = request) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessRequest(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process request + Process fwd_response + Process fwd_response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process request + Process fwd_response + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process request + Process response + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = request) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = response) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessRequest(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessResponse(n2, EntryPath[n2]);
                if IntentToSendRequest[n2] = 2 then
                    IntentToSendRequest[n2] := 1
                endif;
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Process fwd_response + Process fwd_response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n3]][n3] < BufferSpace) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessFwdResponse(n3, EntryPath[n3], ExitPath[n3]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Process fwd_response + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n2]][n2] < BufferSpace) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessFwdResponse(n2, EntryPath[n2], ExitPath[n2]);
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Process response + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n1]][n1] < BufferSpace) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = response) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessFwdResponse(n1, EntryPath[n1], ExitPath[n1]);
                    ProcessResponse(n2, EntryPath[n2]);
                if IntentToSendRequest[n2] = 2 then
                    IntentToSendRequest[n2] := 1
                endif;
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        ruleset n3: 0..NumberNodes-1 do
                rule "Rule --> Process response + Process response + Process response"
                    (IncomingQueue[n1][EntryPath[n1]][0].msg_type = response) & (IntentToSendRequest[n1] != 1) & 
                    (IncomingQueue[n2][EntryPath[n2]][0].msg_type = response) & (IntentToSendRequest[n2] != 1) & 
                    (IncomingQueue[n3][EntryPath[n3]][0].msg_type = response) & (IntentToSendRequest[n3] != 1) & 
                    (n1 != n2) & 
                    (n1 != n3) & 
                    (n2 != n3)
                ==>
                Begin
                    ProcessResponse(n1, EntryPath[n1]);
                if IntentToSendRequest[n1] = 2 then
                    IntentToSendRequest[n1] := 1
                endif;
                    ProcessResponse(n2, EntryPath[n2]);
                if IntentToSendRequest[n2] = 2 then
                    IntentToSendRequest[n2] := 1
                endif;
                    ProcessResponse(n3, EntryPath[n3]);
                if IntentToSendRequest[n3] = 2 then
                    IntentToSendRequest[n3] := 1
                endif;
                endrule;
        endruleset;
    endruleset;
endruleset;
