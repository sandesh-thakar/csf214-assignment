/*! \mainpage CS F214 Assignment Part 1
 * \section Authors
 * 1. Sandesh Thakar(2017A7PS0181H)
 * 2. Kushagra Srivastava(2017A7PS0146H)
 * 3. Kunal Verma(2017A7PS0120H)

 * \section Tasks
 * Task 1: Write a function to convert the infix propositional logic expression into a postfix propositional logic expression.
 * \n Task 2: Write a function to convert the postfix expression into a rooted binary parse tree.
 * \n Task 3: Write a function to traverse the parse tree to output the infix expression back by in-order traversal of the parse tree.


 * \section Assumptions
 * The expression should be perfectly paranthesized
 * \n Example 1: (a^b) is perfectly paranthesized while a^b is not
 * \n Example 2: ((~p)^q) is perfectly paranthesized while (~p^q) is not

 *\section Sample
 * Input
 * \n Enter infix expression: (((~p)^(qV(~p)))>p)
 * \n Output
 * \n Postfix expression is: p~qp~V^p>
 * \n Infix expression after inoder traversal of parse tree: (((~p)^(qV(~p)))>p)
 */