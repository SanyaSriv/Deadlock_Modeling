- Experiment 1: without any flow control strategy. 
Command ran: `./BasicModel`
Result: With this, we get into a state of deadlock. It is defined below: 

Unpacking state from queue:
Network[0][0]:1
Network[0][1]:1
Network[1][0]:1
Network[1][1]:1
IncomingQueue[0][0][0].msg_type:empty
IncomingQueue[0][0][0].dest_nid:Undefined
IncomingQueue[0][0][0].src_nid:Undefined
IncomingQueue[0][0][1].msg_type:empty
IncomingQueue[0][0][1].dest_nid:Undefined
IncomingQueue[0][0][1].src_nid:Undefined
IncomingQueue[0][0][2].msg_type:empty
IncomingQueue[0][0][2].dest_nid:Undefined
IncomingQueue[0][0][2].src_nid:Undefined
IncomingQueue[0][0][3].msg_type:empty
IncomingQueue[0][0][3].dest_nid:Undefined
IncomingQueue[0][0][3].src_nid:Undefined
IncomingQueue[0][0][4].msg_type:empty
IncomingQueue[0][0][4].dest_nid:Undefined
IncomingQueue[0][0][4].src_nid:Undefined
IncomingQueue[0][1][0].msg_type:request
IncomingQueue[0][1][0].dest_nid:0
IncomingQueue[0][1][0].src_nid:1
IncomingQueue[0][1][1].msg_type:request
IncomingQueue[0][1][1].dest_nid:0
IncomingQueue[0][1][1].src_nid:1
IncomingQueue[0][1][2].msg_type:request
IncomingQueue[0][1][2].dest_nid:0
IncomingQueue[0][1][2].src_nid:1
IncomingQueue[0][1][3].msg_type:request
IncomingQueue[0][1][3].dest_nid:0
IncomingQueue[0][1][3].src_nid:1
IncomingQueue[0][1][4].msg_type:request
IncomingQueue[0][1][4].dest_nid:0
IncomingQueue[0][1][4].src_nid:1
IncomingQueue[1][0][0].msg_type:request
IncomingQueue[1][0][0].dest_nid:1
IncomingQueue[1][0][0].src_nid:0
IncomingQueue[1][0][1].msg_type:request
IncomingQueue[1][0][1].dest_nid:1
IncomingQueue[1][0][1].src_nid:0
IncomingQueue[1][0][2].msg_type:request
IncomingQueue[1][0][2].dest_nid:1
IncomingQueue[1][0][2].src_nid:0
IncomingQueue[1][0][3].msg_type:request
IncomingQueue[1][0][3].dest_nid:1
IncomingQueue[1][0][3].src_nid:0
IncomingQueue[1][0][4].msg_type:request
IncomingQueue[1][0][4].dest_nid:1
IncomingQueue[1][0][4].src_nid:0
IncomingQueue[1][1][0].msg_type:empty
IncomingQueue[1][1][0].dest_nid:Undefined
IncomingQueue[1][1][0].src_nid:Undefined
IncomingQueue[1][1][1].msg_type:empty
IncomingQueue[1][1][1].dest_nid:Undefined
IncomingQueue[1][1][1].src_nid:Undefined
IncomingQueue[1][1][2].msg_type:empty
IncomingQueue[1][1][2].dest_nid:Undefined
IncomingQueue[1][1][2].src_nid:Undefined
IncomingQueue[1][1][3].msg_type:empty
IncomingQueue[1][1][3].dest_nid:Undefined
IncomingQueue[1][1][3].src_nid:Undefined
IncomingQueue[1][1][4].msg_type:empty
IncomingQueue[1][1][4].dest_nid:Undefined
IncomingQueue[1][1][4].src_nid:Undefined
TailPointers[0][0]:0
TailPointers[0][1]:5
TailPointers[1][0]:5
TailPointers[1][1]:0


We can construct the deadlock cycle using our formalism. This is also like a proof that the formalism is correct. 



- Experiment 2: To simulate the queue-clear-first invariant. I add another clause in the send request rule that makes sure that the tail pointer of the node that wants to send a request is 0. (Implying that this node’s incoming buffer is empty). Important thing to note: if there are 4 nodes that are in a fully connected topology. If node 1 wants to send a message to node 2, then it needs to make sure its incoming buffer for the link that connects it to node 2 is empty. All of its other incoming buffers can be filled up. This is because no third node can ever interfere in the interactions between these 2 nodes, so they kind of act independently. 
Command ran: `./QueueClearFirst`
Result: No deadlocks were found.

The following rules were not fired, but I think it is fine because there were no edges between them: 

Rules Information:

        Fired 0 times   - Rule "Process Response, n2:0, n1:0"
        Fired 81 times  - Rule "Process Response, n2:1, n1:0"
        Fired 81 times  - Rule "Process Response, n2:0, n1:1"
        Fired 0 times   - Rule "Process Response, n2:1, n1:1"
        Fired 0 times   - Rule "Process Request -> Send Response, n2:0, n1:0"
        Fired 50 times  - Rule "Process Request -> Send Response, n2:1, n1:0"
        Fired 50 times  - Rule "Process Request -> Send Response, n2:0, n1:1"
        Fired 0 times   - Rule "Process Request -> Send Response, n2:1, n1:1"
        Fired 0 times   - Rule "Send Request, nid2:0, nid1:0"
        Fired 60 times  - Rule "Send Request, nid2:1, nid1:0"
        Fired 60 times  - Rule "Send Request, nid2:0, nid1:1"
        Fired 0 times   - Rule "Send Request, nid2:1, nid1:1"

Basically, these unfired rules represent self loops. I am not sure why some rules were fired more than the others. 

Experiment 3: Testing Process and Send - methodology 1. 
For this implementation, I used a token method. Every node had an intent token for every physical link. For example,
if a node was connected to 3 other nodes, then it would have an intent token for all 3 of them. If the intent token is 0
for a pair (x, y), then it implies node x does not want to send its reqest to node y. When node x wants to send a request,
either its incoming buffer (associated to y) is supposed to be empty, or it should process the message at the head of its
incoming buffer first. Hence, in the code, if the incoming buffer is empty, then the node is allowed to go ahead and send the request. 
If it is not empty, then the intent token is set to 2. When a node would process a response or a request sitting at the head of the buffer, then the token would turn to 1. Because, now the node will have a token to send its own request, it would be able to
go ahead and send its own request. After sending the request, its token be set to 0 again.
Command Ran: `./ProcessAndSend`

Result: A deadlock is found. It happens because both the nodes in the fully connected topology can have 1 space remaining,
and also simultaneously hold a token. Node 0 will use its token to occupy the last space in node 1's buffer, and node 1 will
use its token to occupy the last space in node 0's buffer. This would cause a deadlock. 
I initially thought that this is because nodes are `hoarding` the tokens or reserving the request token until the end instead
of immediately using it. I implemented some functionality to counter this, but it still did not prevent the deadlock.
Then, I also implemented a system in which a node would have to process 2 messages in order to send 1 request of its own.
There is still a deadlock in that case. The code for this is stored in the file `ProcessAndSend2.m`.

- Experiment 3: I made another variant of the same protocol as before. My initial point of view about the process and send
protocol was that it makes sure 1 space is empty in each buffer before they send their own requests. However, the token
way of implementing things does not really work. So, I implemeted the same protocol in a slightly different way. 
Instead of having any tokens, I made a rule that a node would only be allowed to send a request if it has atleast 1 empty
space in the buffer. This rule also simulates our invariant. If the node's incoming buffer is empty, then it is allowed to send
a request. If a node's buffer is filled up, then it cannot send a request without first processing a message, because the rules
encoded in Murphi do not permit this behavior. 
Command Ran: `./LastSpaceEmpty`

Result: There is no deadlock. However, I am not able to reason out whether this protocol is the same as process and send. 
