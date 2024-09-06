/* Variables for Node = N0 */
Var N0_VN0_link0_space0 : boolean; /*Head = Tail*/

Var N0_VN1_link0_space0 : boolean; /*Head = Tail*/

/* Variables for Node = N1 */
Var N1_VN0_link0_space0 : boolean; /*Head = Tail*/

Var N1_VN1_link0_space0 : boolean; /*Head = Tail*/


/*In the start space, all buffer spaces should be available, 
False indicates that 
no content is there in that space and it is empty.*/
StartState
Begin
    N0_VN0_link0_space0 := false;

	N0_VN1_link0_space0 := false;

	N1_VN0_link0_space0 := false;

	N1_VN1_link0_space0 := false;
End;

Rule "Send request to N0"
	!N0_VN0_link0_space0
==>
Begin
	N0_VN0_link0_space0 := true; /*Space is now occupied*/
End;

Rule "Send request to N1"
	!N1_VN0_link0_space0
==>
Begin
	N1_VN0_link0_space0 := true; /*Space is now occupied*/
End;

Rule "Process Request - Send response to N1"
	(N0_VN0_link0_space0 & !N1_VN1_link0_space0)
==>
Begin
	N0_VN0_link0_space0 := false; /*Space is free*/
    N1_VN1_link0_space0 := true; /*Response is sent*/
End;

Rule "Process Request - Send response to N0"
	(N1_VN0_link0_space0 & !N0_VN1_link0_space0)
==>
Begin
	N1_VN0_link0_space0 := false; /*Space is free*/
    N0_VN1_link0_space0 := true; /*Response is sent*/
End;

Rule "Process Response - N0"
    N0_VN1_link0_space0
==>
Begin
    N0_VN1_link0_space0 := false;
End;

Rule "Process Response - N1"
    N1_VN1_link0_space0
==>
Begin
    N1_VN1_link0_space0 := false;
End;



