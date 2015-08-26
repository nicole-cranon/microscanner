# A Micro Scanner
The scanner will be a function of no arguments that returns Token values.

**type** 
Token **is** (BeginSym, EndSym, ReadSym, WriteSym, Id, IntLiteral, LParen,
RParen, SemiColon, Comma, AssignOp, PlusOp, MinusOp, EofSym); 

TokenBuffer: String

**function** Scanner **return** Token; 
	The following routines will be used: 


	*Read  
		Inspect — 
			The next input character is read; error if Eof is true.
			The next input character is returned, but input is not advanced; error if Eof is true.
		Advance - 
			The next input character is removed, but not returned; no effect at end of file.
 
	*Eof -
		True at the end of file.

	*BufferChar —  
		Adds its argument to a character buffer called TokenBuffer. This buffer is visible to any part of the compiler, and always contains the text of the most recently scanned token. The content of TokenBuffer will be used particularly by semantic routines. Of course, the characters of this buffer also are used by CheckReserved to determine whether a token that looks like an identifier is actually a reserved word.

	*ClearBuffer —  
		Reset the buffer TokenBuffer to the empty string

	*CheckReserved —  
		Takes the identifiers as they are recognized and returns the proper token class (either Id or some reserved word).


**Extended Micro Grammer** 
1. <program> -> begin <stmt list> end 
2. <stmt list> -> <statement> | <statement> <stmt list> 
3. <statement> -> Id := <expression>; 
4. <statement> -> read (<id list>); 
5. <statement> -> write (<expr list>); 
6. <id list> -> Id | Id, <id list> 
7. <expr list> -> <expression> | <expression>, <expr list> 
8. <bool expression> -> <expression> = <expression> 
9. <expression> -> <exponential> | <exponential> + <expression> | <exponential> - <expression> 
10. <exponential> -> <primary> | <primary> ** <exponential> 
11. <primary> -> Id 
12. <primary> -> IntLiteral 
13. <primary> -> (<expression>) 
14. <add op> -> + | - 
15. <exp op> -> ** 
16. <system goal> -> <program>$ 