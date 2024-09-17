const
  NumberNodes: 3; -- There should be 3 nodes in the system
  BufferSpace: 2;
  NumberAddresses: 4;
  NumberOfTokens: 3;

type MessageState: enum {empty, response, request};

type NodeIDs: 0..NumberNodes-1;

Message: Record
	msg_type: MessageState;
    dest_nid: NodeIDs;
    src_nid: NodeIDs;
	End;

type Queue: array[0..BufferSpace-1] of Message;

var IncomingQueue: array[NodeIDs] of Queue;
var TailPointers: array[NodeIDs] of 0..BufferSpace;
var NumberTokens: 0..NumberOfTokens;
/*initializing all the spaces here*/

/*Implementing the network logic here*/
var Network: array[NodeIDs] of array[NodeIDs] of 0..1;

procedure SendRequest(msg_type:MessageState; src_nid:NodeIDs; dest_nid:NodeIDs);
    var msg_to_send: Message;
begin
    msg_to_send.msg_type := msg_type;
    msg_to_send.src_nid := src_nid;
    msg_to_send.dest_nid := dest_nid;

    /*Add this message to the destination buffer*/
    IncomingQueue[dest_nid][TailPointers[dest_nid]] := msg_to_send;
    TailPointers[dest_nid] := TailPointers[dest_nid] + 1;

    /*Reduce a token from the system.*/
    NumberTokens := NumberTokens - 1;
end;

Procedure ProcessResponse(src_nid:NodeIDs);
begin
    /*Process the response and free up the space.
    Shift everything to the right space by 1.*/
  for i: 1..BufferSpace-1 do
    IncomingQueue[src_nid][i - 1] := IncomingQueue[src_nid][i];
  endfor;
  IncomingQueue[src_nid][TailPointers[src_nid] - 1].msg_type := empty;
  TailPointers[src_nid] := TailPointers[src_nid] - 1;
  
  /*Increase a token in the system.*/
  NumberTokens := NumberTokens + 1;

End;

Procedure ProcessRequest(src_nid: NodeIDs);
    /*Process the request
    Free up a space in the source buffer.
    Send a response to the destination buffer
    This procedure will not check for the availability of the space.
    Instead, I am assuming it is the responsibility of the transition function.*/
  
  /*Make the response message that should be sent*/
   var msg_to_send: Message;
Begin
   msg_to_send.msg_type := response;
   msg_to_send.src_nid := IncomingQueue[src_nid][0].dest_nid;
   msg_to_send.dest_nid := IncomingQueue[src_nid][0].src_nid;

  for i: 1..BufferSpace-1 do
    IncomingQueue[src_nid][i - 1] := IncomingQueue[src_nid][i];
  endfor;
  IncomingQueue[src_nid][TailPointers[src_nid] - 1].msg_type := empty;

  TailPointers[src_nid] := TailPointers[src_nid] - 1;
  
  IncomingQueue[msg_to_send.dest_nid][TailPointers[msg_to_send.dest_nid]] := msg_to_send;
  TailPointers[msg_to_send.dest_nid] := TailPointers[msg_to_send.dest_nid] + 1;
  
  /*This is more like the intermediate state between processing a request and a response.
  This is why we do not do any token exchnage in here.*/
End;

StartState
Begin
    for nid:0..NumberNodes-1 do
        for s:0..BufferSpace-1 do
            IncomingQueue[nid][s].msg_type := empty;
        endfor;
        TailPointers[nid] := 0;
    endfor;
    NumberTokens := NumberOfTokens;

    for nid:0..NumberNodes-1 do
        for nid2:0..NumberNodes - 1 do
            Network[nid][nid2] := 0;

    Network[0][1] := 1; /*Link 1*/
    Network[1][2] := 1; /*Link 2*/
    Network[2][0] := 1; /*Link 3*/

end;

/*Defining all of the rules here*/

ruleset nid1: 0..NumberNodes-1 do 
    ruleset nid2: 0..NumberNodes-1 do 
        rule "Send Request"
           (NumberTokens > 0) & (nid1 != nid2) & (TailPointers[nid2] < BufferSpace)
        ==>
        Begin
            SendRequest(request, nid1, nid2); /*Fire the procedure*/
        endrule;
    endruleset;
endruleset;

ruleset nid: 0..NumberNodes-1 do
    rule "Process Request -> Send Response"
        (IncomingQueue[nid][0].msg_type = request) & (TailPointers[IncomingQueue[nid][0].src_nid] < BufferSpace)
    ==>
    Begin
        ProcessRequest(nid); /*Fire the procedure*/
    endrule;
endruleset;

ruleset nid: 0..NumberNodes-1 do
    rule "Process Response"
        (IncomingQueue[nid][0].msg_type = response)
    ==>
    Begin
        ProcessResponse(nid); /*Fire the procedure*/
    endrule;
endruleset;


/*
Forwarding logic I am implementing for now: 

1. If you are directly connected to that node --> well and good.
2. Otherwise, send it to the node you are connected to, and then send it to the neighbor and the neighbour
will figure out.
3. There is a chain, so somehow we will reach the actual destination.
*/