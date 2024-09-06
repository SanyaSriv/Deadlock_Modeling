# Deadlock_Modeling

--------------------------------
**simple.m**

Protocol has 2 nodes - N0 and N1.
Each node has 2 VNs - VN0 and VN1. VN0 acts like a request buffer, and VN1 acts like a response buffer.
The buffers have 1 space so head = tail.
There are 3 kinds of actions - 
- Processing a response
- Sending a request
- Sending a response

Result with Murphi - 16 states, 40 rules fired in 0.10s. No deadlocks were detected. 

--------------------------------
**simple_combined_res_req_buf.m**

Protocol has 2 nodes - N0 and N1.
Each node has 1 VN - VN0. Hence, the requests and responses get queued in the same buffer. 
Each buffer has only 1 space, so head = tail.
There are 3 kinds of actions - 
- Processing a response
- Sending a request
- Sending a response

Result with Murphi - Deadlock state is found (which was expected).

```Unpacking state from queue:
N0_VN0_link0_space0:response
N1_VN0_link0_space0:empty

The following next states are obtained:

Firing rule Send request to N1
Obtained state:
N0_VN0_link0_space0:response
N1_VN0_link0_space0:request

------------------------------
Unpacking state from queue:
N0_VN0_link0_space0:request
N1_VN0_link0_space0:request
```

--------------------------------
**simple_combined_res_req_buf2.m**

Protocol has 2 nodes - N0 and N1.
Each node has 1 VN - VN0. Hence, the requests and responses get queued in the same buffer. 
Each buffer has 2 spaces space, so head != tail.
There are 4 kinds of actions - 
- Processing a response
- Sending a request
- Sending a response
- Move request/response forward in the buffer. For example, if there was a
response at the head which gets processed, then the request/response at the tail
should be moved up to the head. 

Result with Murphi - Deadlock state is found (which was expected).

```
Unpacking state from queue:
N0_VN0_link0_space0:request
N0_VN0_link0_space1:request
N1_VN0_link0_space0:request
N1_VN0_link0_space1:request
```

--------------------------------