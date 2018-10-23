#include <bits/stdc++.h>
#include "InfixToPostfix.cpp"
#include "InorderTraversal.cpp"
using namespace std;

int main()
{
	cout<<"Enter infix expression: ";

	string in;
	cin>>in;

	string postfix_expression=InfixToPostfix::infix_to_postfix(in);

	cout<<"Postfix expression is: "<<postfix_expression<<"\n";

	cout<<"Infix expression after inoder traversal of parse tree: ";
	InorderTraversal::postfix_to_parse_tree(postfix_expression);
	cout<<"\n";
}