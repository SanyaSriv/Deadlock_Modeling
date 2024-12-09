/*Defining the macros here*/
const
  NumberNodes: 4;
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
var Routers: array[NodeIDs] of 0..1;
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
    for nid:0..NumberNodes-1 do
        Routers[nid] := 0;
    endfor;

    Routers[1] := 1;
    Routers[3] := 1;

    
end;

ruleset n5: 0..NumberNodes-1 do
        rule "Rule --> Process request"
            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (IntentToSendRequest[n5] != 1)
        ==>
        Begin
            ProcessRequest(n5, EntryPath[n5], ExitPath[n5]);
        endrule;
endruleset;


ruleset n5: 0..NumberNodes-1 do
        rule "Rule --> Process fwd_response"
            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace)
        ==>
        Begin
            ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
        endrule;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Send request"
                (n5 != n6) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (Routers[n5] = 0) & (Routers[n6] = 0) & (IntentToSendRequest[n5] != 2)
            ==>
            Begin
                if ((IntentToSendRequest[n5] = 1) | (TailPointers[n5][EntryPath[n5]] = 0)) then 
             SendRequest(n5, ExitPath[n5], n6); 
             IntentToSendRequest[n5] := 0; 
             else 
             IntentToSendRequest[n5] := 2; 
             endif;
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
        rule "Rule --> Process response"
            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = response) & (IntentToSendRequest[n5] != 1)
        ==>
        Begin
            ProcessResponse(n5, EntryPath[n5]); 
         if IntentToSendRequest[n5] = 2 then 
         IntentToSendRequest[n5] := 1; 
         endif;
        endrule;
endruleset;


ruleset n5: 0..NumberNodes-1 do
        rule "Rule --> Process fwd_request"
            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace)
        ==>
        Begin
            ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
        endrule;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process request + Process response"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (IntentToSendRequest[n5] != 1) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = response) & (IntentToSendRequest[n6] != 1) & 
                (n5 != n6)
            ==>
            Begin
                ProcessRequest(n5, EntryPath[n5], ExitPath[n5]);
                ProcessResponse(n6, EntryPath[n6]); 
             if IntentToSendRequest[n6] = 2 then 
             IntentToSendRequest[n6] := 1; 
             endif;
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process response + Send request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = response) & (IntentToSendRequest[n5] != 1) & 
                    (n6 != n7) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (Routers[n6] = 0) & (Routers[n7] = 0) & (IntentToSendRequest[n6] != 2) & 
                    (n5 != n6)
                ==>
                Begin
                    ProcessResponse(n5, EntryPath[n5]); 
                 if IntentToSendRequest[n5] = 2 then 
                 IntentToSendRequest[n5] := 1; 
                 endif;
                    if ((IntentToSendRequest[n6] = 1) | (TailPointers[n6][EntryPath[n6]] = 0)) then 
                 SendRequest(n6, ExitPath[n6], n7); 
                 IntentToSendRequest[n6] := 0; 
                 else 
                 IntentToSendRequest[n6] := 2; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process response + Process response"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = response) & (IntentToSendRequest[n5] != 1) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = response) & (IntentToSendRequest[n6] != 1) & 
                (n5 != n6)
            ==>
            Begin
                ProcessResponse(n5, EntryPath[n5]); 
             if IntentToSendRequest[n5] = 2 then 
             IntentToSendRequest[n5] := 1; 
             endif;
                ProcessResponse(n6, EntryPath[n6]); 
             if IntentToSendRequest[n6] = 2 then 
             IntentToSendRequest[n6] := 1; 
             endif;
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_request + Process request"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                (n5 != n6)
            ==>
            Begin
                ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_request + Process fwd_response"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                (n5 != n6)
            ==>
            Begin
                ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Send request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (n6 != n7) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (Routers[n6] = 0) & (Routers[n7] = 0) & (IntentToSendRequest[n6] != 2) & 
                    (n5 != n6)
                ==>
                Begin
                    ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                    if ((IntentToSendRequest[n6] = 1) | (TailPointers[n6][EntryPath[n6]] = 0)) then 
                 SendRequest(n6, ExitPath[n6], n7); 
                 IntentToSendRequest[n6] := 0; 
                 else 
                 IntentToSendRequest[n6] := 2; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_request + Process response"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = response) & (IntentToSendRequest[n6] != 1) & 
                (n5 != n6)
            ==>
            Begin
                ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                ProcessResponse(n6, EntryPath[n6]); 
             if IntentToSendRequest[n6] = 2 then 
             IntentToSendRequest[n6] := 1; 
             endif;
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_response + Process request"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                (n5 != n6)
            ==>
            Begin
                ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_response + Process fwd_response"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                (n5 != n6)
            ==>
            Begin
                ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_request + Process fwd_request"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                (n5 != n6)
            ==>
            Begin
                ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Send request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (n6 != n7) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (Routers[n6] = 0) & (Routers[n7] = 0) & (IntentToSendRequest[n6] != 2) & 
                    (n5 != n6)
                ==>
                Begin
                    ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                    if ((IntentToSendRequest[n6] = 1) | (TailPointers[n6][EntryPath[n6]] = 0)) then 
                 SendRequest(n6, ExitPath[n6], n7); 
                 IntentToSendRequest[n6] := 0; 
                 else 
                 IntentToSendRequest[n6] := 2; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Send request + Send request"
                        (n5 != n6) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (Routers[n5] = 0) & (Routers[n6] = 0) & (IntentToSendRequest[n5] != 2) & 
                        (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                        (n5 != n7)
                    ==>
                    Begin
                        if ((IntentToSendRequest[n5] = 1) | (TailPointers[n5][EntryPath[n5]] = 0)) then 
                     SendRequest(n5, ExitPath[n5], n6); 
                     IntentToSendRequest[n5] := 0; 
                     else 
                     IntentToSendRequest[n5] := 2; 
                     endif;
                        if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                     SendRequest(n7, ExitPath[n7], n8); 
                     IntentToSendRequest[n7] := 0; 
                     else 
                     IntentToSendRequest[n7] := 2; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process request + Process request"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (IntentToSendRequest[n5] != 1) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                (n5 != n6)
            ==>
            Begin
                ProcessRequest(n5, EntryPath[n5], ExitPath[n5]);
                ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
            rule "Rule --> Process fwd_response + Process response"
                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = response) & (IntentToSendRequest[n6] != 1) & 
                (n5 != n6)
            ==>
            Begin
                ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                ProcessResponse(n6, EntryPath[n6]); 
             if IntentToSendRequest[n6] = 2 then 
             IntentToSendRequest[n6] := 1; 
             endif;
            endrule;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process request + Send request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & (IntentToSendRequest[n5] != 1) & 
                    (n6 != n7) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (Routers[n6] = 0) & (Routers[n7] = 0) & (IntentToSendRequest[n6] != 2) & 
                    (n5 != n6)
                ==>
                Begin
                    ProcessRequest(n5, EntryPath[n5], ExitPath[n5]);
                    if ((IntentToSendRequest[n6] = 1) | (TailPointers[n6][EntryPath[n6]] = 0)) then 
                 SendRequest(n6, ExitPath[n6], n7); 
                 IntentToSendRequest[n6] := 0; 
                 else 
                 IntentToSendRequest[n6] := 2; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_response + Process request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Process fwd_response + Process request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Process request + Process request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_response + Send request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n6 != n7)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                        if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                     SendRequest(n7, ExitPath[n7], n8); 
                     IntentToSendRequest[n7] := 0; 
                     else 
                     IntentToSendRequest[n7] := 2; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process fwd_response + Send request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n6 != n7)
                    ==>
                    Begin
                        ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                        if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                     SendRequest(n7, ExitPath[n7], n8); 
                     IntentToSendRequest[n7] := 0; 
                     else 
                     IntentToSendRequest[n7] := 2; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process request + Process request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_response + Process response"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessResponse(n7, EntryPath[n7]); 
                 if IntentToSendRequest[n7] = 2 then 
                 IntentToSendRequest[n7] := 1; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process request + Send request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                        (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n6 != n7)
                    ==>
                    Begin
                        ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
                        if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                     SendRequest(n7, ExitPath[n7], n8); 
                     IntentToSendRequest[n7] := 0; 
                     else 
                     IntentToSendRequest[n7] := 2; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Process fwd_response + Process response"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessResponse(n7, EntryPath[n7]); 
                 if IntentToSendRequest[n7] = 2 then 
                 IntentToSendRequest[n7] := 1; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                        rule "Rule --> Process fwd_response + Send request + Send request"
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                            (n6 != n7) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (Routers[n6] = 0) & (Routers[n7] = 0) & (IntentToSendRequest[n6] != 2) & 
                            (n8 != n9) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (Routers[n8] = 0) & (Routers[n9] = 0) & (IntentToSendRequest[n8] != 2) & 
                            (n5 != n6) & 
                            (n5 != n8) & 
                            (n6 != n8)
                        ==>
                        Begin
                            ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                            if ((IntentToSendRequest[n6] = 1) | (TailPointers[n6][EntryPath[n6]] = 0)) then 
                         SendRequest(n6, ExitPath[n6], n7); 
                         IntentToSendRequest[n6] := 0; 
                         else 
                         IntentToSendRequest[n6] := 2; 
                         endif;
                            if ((IntentToSendRequest[n8] = 1) | (TailPointers[n8][EntryPath[n8]] = 0)) then 
                         SendRequest(n8, ExitPath[n8], n9); 
                         IntentToSendRequest[n8] := 0; 
                         else 
                         IntentToSendRequest[n8] := 2; 
                         endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process request + Send request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                        (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n6 != n7)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
                        if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                     SendRequest(n7, ExitPath[n7], n8); 
                     IntentToSendRequest[n7] := 0; 
                     else 
                     IntentToSendRequest[n7] := 2; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Process request + Process response"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessResponse(n7, EntryPath[n7]); 
                 if IntentToSendRequest[n7] = 2 then 
                 IntentToSendRequest[n7] := 1; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                        rule "Rule --> Process fwd_request + Send request + Send request"
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                            (n6 != n7) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (Routers[n6] = 0) & (Routers[n7] = 0) & (IntentToSendRequest[n6] != 2) & 
                            (n8 != n9) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (Routers[n8] = 0) & (Routers[n9] = 0) & (IntentToSendRequest[n8] != 2) & 
                            (n5 != n6) & 
                            (n5 != n8) & 
                            (n6 != n8)
                        ==>
                        Begin
                            ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                            if ((IntentToSendRequest[n6] = 1) | (TailPointers[n6][EntryPath[n6]] = 0)) then 
                         SendRequest(n6, ExitPath[n6], n7); 
                         IntentToSendRequest[n6] := 0; 
                         else 
                         IntentToSendRequest[n6] := 2; 
                         endif;
                            if ((IntentToSendRequest[n8] = 1) | (TailPointers[n8][EntryPath[n8]] = 0)) then 
                         SendRequest(n8, ExitPath[n8], n9); 
                         IntentToSendRequest[n8] := 0; 
                         else 
                         IntentToSendRequest[n8] := 2; 
                         endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process request + Process response"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & (IntentToSendRequest[n6] != 1) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessRequest(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessResponse(n7, EntryPath[n7]); 
                 if IntentToSendRequest[n7] = 2 then 
                 IntentToSendRequest[n7] := 1; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process response + Send request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = response) & (IntentToSendRequest[n6] != 1) & 
                        (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n6 != n7)
                    ==>
                    Begin
                        ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessResponse(n6, EntryPath[n6]); 
                     if IntentToSendRequest[n6] = 2 then 
                     IntentToSendRequest[n6] := 1; 
                     endif;
                        if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                     SendRequest(n7, ExitPath[n7], n8); 
                     IntentToSendRequest[n7] := 0; 
                     else 
                     IntentToSendRequest[n7] := 2; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_request + Process request"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_response + Process response + Process response"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = response) & (IntentToSendRequest[n6] != 1) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessResponse(n6, EntryPath[n6]); 
                 if IntentToSendRequest[n6] = 2 then 
                 IntentToSendRequest[n6] := 1; 
                 endif;
                    ProcessResponse(n7, EntryPath[n7]); 
                 if IntentToSendRequest[n7] = 2 then 
                 IntentToSendRequest[n7] := 1; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_request + Send request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n6 != n7)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                        if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                     SendRequest(n7, ExitPath[n7], n8); 
                     IntentToSendRequest[n7] := 0; 
                     else 
                     IntentToSendRequest[n7] := 2; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process response + Send request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = response) & (IntentToSendRequest[n6] != 1) & 
                        (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n6 != n7)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessResponse(n6, EntryPath[n6]); 
                     if IntentToSendRequest[n6] = 2 then 
                     IntentToSendRequest[n6] := 1; 
                     endif;
                        if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                     SendRequest(n7, ExitPath[n7], n8); 
                     IntentToSendRequest[n7] := 0; 
                     else 
                     IntentToSendRequest[n7] := 2; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process fwd_request + Process response"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                    ProcessResponse(n7, EntryPath[n7]); 
                 if IntentToSendRequest[n7] = 2 then 
                 IntentToSendRequest[n7] := 1; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
                rule "Rule --> Process fwd_request + Process response + Process response"
                    (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                    (IncomingQueue[n6][EntryPath[n6]][0].msg_type = response) & (IntentToSendRequest[n6] != 1) & 
                    (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                    (n5 != n6) & 
                    (n5 != n7) & 
                    (n6 != n7)
                ==>
                Begin
                    ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                    ProcessResponse(n6, EntryPath[n6]); 
                 if IntentToSendRequest[n6] = 2 then 
                 IntentToSendRequest[n6] := 1; 
                 endif;
                    ProcessResponse(n7, EntryPath[n7]); 
                 if IntentToSendRequest[n7] = 2 then 
                 IntentToSendRequest[n7] := 1; 
                 endif;
                endrule;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                    ruleset n10: 0..NumberNodes-1 do
                            rule "Rule --> Process fwd_request + Process fwd_response + Send request + Send request"
                                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                                (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                                (n9 != n10) & (TailPointers[ExitPath[n9]][n9] < BufferSpace) & (Routers[n9] = 0) & (Routers[n10] = 0) & (IntentToSendRequest[n9] != 2) & 
                                (n5 != n6) & 
                                (n5 != n7) & 
                                (n5 != n9) & 
                                (n6 != n7) & 
                                (n6 != n9) & 
                                (n7 != n9)
                            ==>
                            Begin
                                ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                                ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                                if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                             SendRequest(n7, ExitPath[n7], n8); 
                             IntentToSendRequest[n7] := 0; 
                             else 
                             IntentToSendRequest[n7] := 2; 
                             endif;
                                if ((IntentToSendRequest[n9] = 1) | (TailPointers[n9][EntryPath[n9]] = 0)) then 
                             SendRequest(n9, ExitPath[n9], n10); 
                             IntentToSendRequest[n9] := 0; 
                             else 
                             IntentToSendRequest[n9] := 2; 
                             endif;
                            endrule;
                    endruleset;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                        rule "Rule --> Process fwd_request + Process fwd_request + Process request + Send request"
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                            (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                            (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                            (n8 != n9) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (Routers[n8] = 0) & (Routers[n9] = 0) & (IntentToSendRequest[n8] != 2) & 
                            (n5 != n6) & 
                            (n5 != n7) & 
                            (n5 != n8) & 
                            (n6 != n7) & 
                            (n6 != n8) & 
                            (n7 != n8)
                        ==>
                        Begin
                            ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                            ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                            ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                            if ((IntentToSendRequest[n8] = 1) | (TailPointers[n8][EntryPath[n8]] = 0)) then 
                         SendRequest(n8, ExitPath[n8], n9); 
                         IntentToSendRequest[n8] := 0; 
                         else 
                         IntentToSendRequest[n8] := 2; 
                         endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_response + Process request + Process response"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = response) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                        ProcessResponse(n8, EntryPath[n8]); 
                     if IntentToSendRequest[n8] = 2 then 
                     IntentToSendRequest[n8] := 1; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                    ruleset n10: 0..NumberNodes-1 do
                            rule "Rule --> Process fwd_request + Process fwd_request + Send request + Send request"
                                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                                (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                                (n9 != n10) & (TailPointers[ExitPath[n9]][n9] < BufferSpace) & (Routers[n9] = 0) & (Routers[n10] = 0) & (IntentToSendRequest[n9] != 2) & 
                                (n5 != n6) & 
                                (n5 != n7) & 
                                (n5 != n9) & 
                                (n6 != n7) & 
                                (n6 != n9) & 
                                (n7 != n9)
                            ==>
                            Begin
                                ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                                ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                                if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                             SendRequest(n7, ExitPath[n7], n8); 
                             IntentToSendRequest[n7] := 0; 
                             else 
                             IntentToSendRequest[n7] := 2; 
                             endif;
                                if ((IntentToSendRequest[n9] = 1) | (TailPointers[n9][EntryPath[n9]] = 0)) then 
                             SendRequest(n9, ExitPath[n9], n10); 
                             IntentToSendRequest[n9] := 0; 
                             else 
                             IntentToSendRequest[n9] := 2; 
                             endif;
                            endrule;
                    endruleset;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_request + Process request + Process response"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = response) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                        ProcessResponse(n8, EntryPath[n8]); 
                     if IntentToSendRequest[n8] = 2 then 
                     IntentToSendRequest[n8] := 1; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                        rule "Rule --> Process fwd_request + Process fwd_request + Process response + Send request"
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                            (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                            (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                            (n8 != n9) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (Routers[n8] = 0) & (Routers[n9] = 0) & (IntentToSendRequest[n8] != 2) & 
                            (n5 != n6) & 
                            (n5 != n7) & 
                            (n5 != n8) & 
                            (n6 != n7) & 
                            (n6 != n8) & 
                            (n7 != n8)
                        ==>
                        Begin
                            ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                            ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                            ProcessResponse(n7, EntryPath[n7]); 
                         if IntentToSendRequest[n7] = 2 then 
                         IntentToSendRequest[n7] := 1; 
                         endif;
                            if ((IntentToSendRequest[n8] = 1) | (TailPointers[n8][EntryPath[n8]] = 0)) then 
                         SendRequest(n8, ExitPath[n8], n9); 
                         IntentToSendRequest[n8] := 0; 
                         else 
                         IntentToSendRequest[n8] := 2; 
                         endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                        rule "Rule --> Process fwd_request + Process fwd_response + Process response + Send request"
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                            (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                            (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                            (n8 != n9) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (Routers[n8] = 0) & (Routers[n9] = 0) & (IntentToSendRequest[n8] != 2) & 
                            (n5 != n6) & 
                            (n5 != n7) & 
                            (n5 != n8) & 
                            (n6 != n7) & 
                            (n6 != n8) & 
                            (n7 != n8)
                        ==>
                        Begin
                            ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                            ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                            ProcessResponse(n7, EntryPath[n7]); 
                         if IntentToSendRequest[n7] = 2 then 
                         IntentToSendRequest[n7] := 1; 
                         endif;
                            if ((IntentToSendRequest[n8] = 1) | (TailPointers[n8][EntryPath[n8]] = 0)) then 
                         SendRequest(n8, ExitPath[n8], n9); 
                         IntentToSendRequest[n8] := 0; 
                         else 
                         IntentToSendRequest[n8] := 2; 
                         endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process fwd_response + Process request + Process request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = request) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                        ProcessRequest(n8, EntryPath[n8], ExitPath[n8]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_request + Process response + Process response"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = response) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessResponse(n7, EntryPath[n7]); 
                     if IntentToSendRequest[n7] = 2 then 
                     IntentToSendRequest[n7] := 1; 
                     endif;
                        ProcessResponse(n8, EntryPath[n8]); 
                     if IntentToSendRequest[n8] = 2 then 
                     IntentToSendRequest[n8] := 1; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_response + Process response + Process response"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = response) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessResponse(n7, EntryPath[n7]); 
                     if IntentToSendRequest[n7] = 2 then 
                     IntentToSendRequest[n7] := 1; 
                     endif;
                        ProcessResponse(n8, EntryPath[n8]); 
                     if IntentToSendRequest[n8] = 2 then 
                     IntentToSendRequest[n8] := 1; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                        rule "Rule --> Process fwd_request + Process fwd_response + Process request + Send request"
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                            (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                            (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                            (n8 != n9) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (Routers[n8] = 0) & (Routers[n9] = 0) & (IntentToSendRequest[n8] != 2) & 
                            (n5 != n6) & 
                            (n5 != n7) & 
                            (n5 != n8) & 
                            (n6 != n7) & 
                            (n6 != n8) & 
                            (n7 != n8)
                        ==>
                        Begin
                            ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                            ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                            ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                            if ((IntentToSendRequest[n8] = 1) | (TailPointers[n8][EntryPath[n8]] = 0)) then 
                         SendRequest(n8, ExitPath[n8], n9); 
                         IntentToSendRequest[n8] := 0; 
                         else 
                         IntentToSendRequest[n8] := 2; 
                         endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                    ruleset n10: 0..NumberNodes-1 do
                            rule "Rule --> Process fwd_response + Process fwd_response + Send request + Send request"
                                (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                                (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                                (n7 != n8) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (Routers[n7] = 0) & (Routers[n8] = 0) & (IntentToSendRequest[n7] != 2) & 
                                (n9 != n10) & (TailPointers[ExitPath[n9]][n9] < BufferSpace) & (Routers[n9] = 0) & (Routers[n10] = 0) & (IntentToSendRequest[n9] != 2) & 
                                (n5 != n6) & 
                                (n5 != n7) & 
                                (n5 != n9) & 
                                (n6 != n7) & 
                                (n6 != n9) & 
                                (n7 != n9)
                            ==>
                            Begin
                                ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                                ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                                if ((IntentToSendRequest[n7] = 1) | (TailPointers[n7][EntryPath[n7]] = 0)) then 
                             SendRequest(n7, ExitPath[n7], n8); 
                             IntentToSendRequest[n7] := 0; 
                             else 
                             IntentToSendRequest[n7] := 2; 
                             endif;
                                if ((IntentToSendRequest[n9] = 1) | (TailPointers[n9][EntryPath[n9]] = 0)) then 
                             SendRequest(n9, ExitPath[n9], n10); 
                             IntentToSendRequest[n9] := 0; 
                             else 
                             IntentToSendRequest[n9] := 2; 
                             endif;
                            endrule;
                    endruleset;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                        rule "Rule --> Process fwd_response + Process fwd_response + Process request + Send request"
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                            (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                            (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                            (n8 != n9) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (Routers[n8] = 0) & (Routers[n9] = 0) & (IntentToSendRequest[n8] != 2) & 
                            (n5 != n6) & 
                            (n5 != n7) & 
                            (n5 != n8) & 
                            (n6 != n7) & 
                            (n6 != n8) & 
                            (n7 != n8)
                        ==>
                        Begin
                            ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                            ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                            ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                            if ((IntentToSendRequest[n8] = 1) | (TailPointers[n8][EntryPath[n8]] = 0)) then 
                         SendRequest(n8, ExitPath[n8], n9); 
                         IntentToSendRequest[n8] := 0; 
                         else 
                         IntentToSendRequest[n8] := 2; 
                         endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process fwd_response + Process request + Process response"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = response) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                        ProcessResponse(n8, EntryPath[n8]); 
                     if IntentToSendRequest[n8] = 2 then 
                     IntentToSendRequest[n8] := 1; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                ruleset n9: 0..NumberNodes-1 do
                        rule "Rule --> Process fwd_response + Process fwd_response + Process response + Send request"
                            (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                            (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                            (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                            (n8 != n9) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (Routers[n8] = 0) & (Routers[n9] = 0) & (IntentToSendRequest[n8] != 2) & 
                            (n5 != n6) & 
                            (n5 != n7) & 
                            (n5 != n8) & 
                            (n6 != n7) & 
                            (n6 != n8) & 
                            (n7 != n8)
                        ==>
                        Begin
                            ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                            ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                            ProcessResponse(n7, EntryPath[n7]); 
                         if IntentToSendRequest[n7] = 2 then 
                         IntentToSendRequest[n7] := 1; 
                         endif;
                            if ((IntentToSendRequest[n8] = 1) | (TailPointers[n8][EntryPath[n8]] = 0)) then 
                         SendRequest(n8, ExitPath[n8], n9); 
                         IntentToSendRequest[n8] := 0; 
                         else 
                         IntentToSendRequest[n8] := 2; 
                         endif;
                        endrule;
                endruleset;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_response + Process fwd_response + Process response + Process response"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = response) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = response) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdResponse(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessResponse(n7, EntryPath[n7]); 
                     if IntentToSendRequest[n7] = 2 then 
                     IntentToSendRequest[n7] := 1; 
                     endif;
                        ProcessResponse(n8, EntryPath[n8]); 
                     if IntentToSendRequest[n8] = 2 then 
                     IntentToSendRequest[n8] := 1; 
                     endif;
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_response + Process request + Process request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_response) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = request) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdResponse(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                        ProcessRequest(n8, EntryPath[n8], ExitPath[n8]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;


ruleset n5: 0..NumberNodes-1 do
    ruleset n6: 0..NumberNodes-1 do
        ruleset n7: 0..NumberNodes-1 do
            ruleset n8: 0..NumberNodes-1 do
                    rule "Rule --> Process fwd_request + Process fwd_request + Process request + Process request"
                        (IncomingQueue[n5][EntryPath[n5]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n5]][n5] < BufferSpace) & 
                        (IncomingQueue[n6][EntryPath[n6]][0].msg_type = fwd_request) & (TailPointers[ExitPath[n6]][n6] < BufferSpace) & 
                        (IncomingQueue[n7][EntryPath[n7]][0].msg_type = request) & (TailPointers[ExitPath[n7]][n7] < BufferSpace) & (IntentToSendRequest[n7] != 1) & 
                        (IncomingQueue[n8][EntryPath[n8]][0].msg_type = request) & (TailPointers[ExitPath[n8]][n8] < BufferSpace) & (IntentToSendRequest[n8] != 1) & 
                        (n5 != n6) & 
                        (n5 != n7) & 
                        (n5 != n8) & 
                        (n6 != n7) & 
                        (n6 != n8) & 
                        (n7 != n8)
                    ==>
                    Begin
                        ProcessFwdRequest(n5, EntryPath[n5], ExitPath[n5]);
                        ProcessFwdRequest(n6, EntryPath[n6], ExitPath[n6]);
                        ProcessRequest(n7, EntryPath[n7], ExitPath[n7]);
                        ProcessRequest(n8, EntryPath[n8], ExitPath[n8]);
                    endrule;
            endruleset;
        endruleset;
    endruleset;
endruleset;