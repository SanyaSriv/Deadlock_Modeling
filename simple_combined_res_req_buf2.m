type SpaceStates: enum {empty, response, request}; 

/* Variables for Node = N0 */
Var N0_VN0_link0_space0 : SpaceStates; /*Head; In this case there is 1 VN and the response and request buffers are combined*/
Var N0_VN0_link0_space1 : SpaceStates; /*Tail*/

/* Variables for Node = N1 */
Var N1_VN0_link0_space0 : SpaceStates; /*Head; In this case there is 1 VN and the response and request buffers are combined*/
Var N1_VN0_link0_space1 : SpaceStates; /*Tail*/

/*In the start space, all buffer spaces should be available, 
False indicates that 
no content is there in that space and it is empty.*/
StartState
Begin
    N0_VN0_link0_space0 := empty;
	N0_VN0_link0_space1 := empty;

	N1_VN0_link0_space0 := empty;
	N1_VN0_link0_space1 := empty;

End;

Rule "Send request to N0"
	(N0_VN0_link0_space1 = empty)
==>
Begin
	N0_VN0_link0_space1 := request; /*Space is now occupied*/
End;

Rule "Move message forward in queue N0"
	((N0_VN0_link0_space1 != empty) & (N0_VN0_link0_space0 = empty))
==>
Begin
	N0_VN0_link0_space0 := N0_VN0_link0_space1;
	N0_VN0_link0_space1 := empty;
End;

Rule "Send request to N1"
	(N1_VN0_link0_space1 = empty)
==>
Begin
	N1_VN0_link0_space1 := request; /*Space is now occupied*/
End;

Rule "Move message forward in queue N1"
	((N1_VN0_link0_space1 != empty) & (N1_VN0_link0_space0 = empty))
==>
Begin
	N1_VN0_link0_space0 := N1_VN0_link0_space1;
	N1_VN0_link0_space1 := empty;
End;

Rule "Process Request - Send response to N1"
	((N0_VN0_link0_space0 = request) & (N1_VN0_link0_space1 = empty))
==>
Begin
	N0_VN0_link0_space0 := empty; /*Space is free*/
    N1_VN0_link0_space1 := response; /*Response is sent*/
End;

Rule "Process Request - Send response to N0"
	((N1_VN0_link0_space0 = request) & (N0_VN0_link0_space1 = empty))
==>
Begin
	N1_VN0_link0_space0 := empty; /*Space is free*/
    N0_VN0_link0_space1 := response; /*Response is sent*/
End;

Rule "Process Response - N0"
    (N1_VN0_link0_space0 = response)
==>
Begin
    N0_VN0_link0_space0 := empty;
End;

Rule "Process Response - N1"
    (N1_VN0_link0_space0 = response)
==>
Begin
    N1_VN0_link0_space0 := empty;
End;

