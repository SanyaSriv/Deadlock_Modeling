# Deadlock_Modeling

--------------------------------
simple.m

Protocol has 2 Nodes - N0 and N1.
Each node has 2 VNs - VN0 and VN1. VN0 acts like a request buffer, and VN1 acts like a response buffer.
The buffers have 1 space so head = tail.
There are 2 kinds of actions - 
- Processing a response
- Sending a request
- Sending a response

Result with Murphi - 16 states, 40 rules fired in 0.10s. No deadlocks were detected. 

--------------------------------