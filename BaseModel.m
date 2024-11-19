/*Defining the macros here*/
const
  NumberNodes: 2; -- There should be 2 nodes in the system
  BufferSpace: 3;

/*A buffer space could either by empty, of filled with a message.
In this protocol, we have a simple request, response system. */
type MessageState: enum {empty, response, request};

/*Defining the node IDs here*/
type NodeIDs: 0..NumberNodes-1; 

Message: Record
    msg_type: MessageState;
    dest_nid: NodeIDs;
    src_nid: NodeIDs;
    End;

type Queue: array[0..BufferSpace-1] of Message;

/*Network[i][j] = 1 := there is a connection from node i to node j*/
var Network: array[NodeIDs] of array[NodeIDs] of 0..1;
/*IncomingQueue[i][j] := incoming link of node i that connects node j
So, it will recieve all the messages node j sends i.*/
var IncomingQueue: array[NodeIDs] of array[NodeIDs] of Queue;
/*To track position of next message insertion in the queue*/
var TailPointers: array[NodeIDs] of array[NodeIDs] of 0..BufferSpace;

procedure SendRequest(msg_type:MessageState; src_nid:NodeIDs; dest_nid:NodeIDs);
    var msg_to_send: Message;
begin
    msg_to_send.msg_type := msg_type;
    msg_to_send.src_nid := src_nid;
    msg_to_send.dest_nid := dest_nid;

    /*Add this message to the destination buffer*/
    IncomingQueue[dest_nid][src_nid][TailPointers[dest_nid][src_nid]] := msg_to_send;
    TailPointers[dest_nid][src_nid] := TailPointers[dest_nid][src_nid] + 1;

end;

Procedure ProcessResponse(src_nid:NodeIDs; dst_nid:NodeIDs);
begin
    /*Process the response and free up the space.
    Shift everything to the right space by 1.*/
  for i: 1..BufferSpace-1 do
    IncomingQueue[src_nid][dst_nid][i - 1] := IncomingQueue[src_nid][dst_nid][i];
    IncomingQueue[src_nid][dst_nid][i].msg_type := empty; /*Reset the space shifted*/
  endfor;
  IncomingQueue[src_nid][dst_nid][TailPointers[src_nid][dst_nid] - 1].msg_type := empty;
  TailPointers[src_nid][dst_nid] := TailPointers[src_nid][dst_nid] - 1;
End;

Procedure ProcessRequest(src_nid: NodeIDs; dst_nid: NodeIDs);
    /*Process the request
    Free up a space in the source buffer.
    Send a response to the destination buffer
    src_nid is going to process a request it recieved from dst_nid.*/
  
  /*Make the response message that should be sent*/
   var msg_to_send: Message;
Begin
   msg_to_send.msg_type := response;
   msg_to_send.src_nid := src_nid;
   msg_to_send.dest_nid := dst_nid;

    /* Shift messages in the source buffer */
    for i := 1 to TailPointers[src_nid][dst_nid] - 1 do
        IncomingQueue[src_nid][dst_nid][i - 1] := IncomingQueue[src_nid][dst_nid][i];
    endfor;

    TailPointers[src_nid][dst_nid] := TailPointers[src_nid][dst_nid] - 1;
    IncomingQueue[src_nid][dst_nid][TailPointers[src_nid][dst_nid]].msg_type := empty;

    /* Add the response message to the destination buffer */
    IncomingQueue[dst_nid][src_nid][TailPointers[dst_nid][src_nid]] := msg_to_send;
    /* Update the tail pointer for the destination buffer */
    TailPointers[dst_nid][src_nid] := TailPointers[dst_nid][src_nid] + 1;
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
        for nid2:0..NumberNodes - 1 do
            /* fully connected graph - every node is connected to every other node*/
            if nid != nid2 then
                Network[nid][nid2] := 1;
            else
                Network[nid][nid2] := 0;
            endif;
        endfor;
    endfor;
end;

/*Defining all the rules here*/
ruleset n1: 0..NumberNodes-1 do 
    ruleset n2: 0..NumberNodes-1 do 
        rule "Send Request"
           (Network[n1][n2] = 1) & (n1 != n2) &
           (TailPointers[n2][n1] < BufferSpace) /*Make sure nid2's buffer has some space*/
        ==>
        Begin
            SendRequest(request, n1, n2); /*Fire the procedure*/
        endrule;
    endruleset;
endruleset;

/*Processing a request and sending a response for it should be an atomic procedure
n1 is processing the request it recieved from n2*/
ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        rule "Process Request -> Send Response"
            (IncomingQueue[n1][n2][0].msg_type = request) & 
            (TailPointers[n2][n1] < BufferSpace) & (n1 != n2)
        ==>
        Begin
            ProcessRequest(n1, n2); /*Fire the procedure*/
        endrule;
    endruleset;
endruleset;

/*Processing a response*/
ruleset n1: 0..NumberNodes-1 do
    ruleset n2: 0..NumberNodes-1 do
        rule "Process Response"
            (IncomingQueue[n1][n2][0].msg_type = response) & (n1 != n2)
        ==>
        Begin
            ProcessResponse(n1, n2); /*Fire the procedure*/
        endrule;
    endruleset;
endruleset;
