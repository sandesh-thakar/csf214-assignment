#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

string infix_to_postfix(string infix)  // Function to convert infix expression to postfix expression
{
	int precedence_index[infix.length()];
	
	int level=0;
	
	for(int i=0;i<infix.length();i++)                                         // Assigning precedence to operators
	{
	    if(infix[i]=='~' || infix[i]=='^' || infix[i]=='V' || infix[i]=='>')
	        precedence_index[i]=level;
	        
	    else if(infix[i]=='(')
	        level++;
	        
	   else if(infix[i]==')')
	        level--;
	}

	stack <char> s;

	string postfix="";

    int current_precedence_index=0;

	for(int i=0;i<infix.length();i++)
	{
		if(infix[i]=='~' || infix[i]=='^' || infix[i]=='V' || infix[i]=='>')
		{
		    
		    if(s.empty())
			{
				s.push(infix[i]);
				current_precedence_index=precedence_index[i];
			}

			else
			{
			 
			    while( !(s.empty()) && (precedence_index[i] <= current_precedence_index)) 
				{
				    char temp=s.top();
					s.pop();
					postfix+=temp;
				}
				s.push(infix[i]);
				current_precedence_index=precedence_index[i];
			}
		}

		else if( (infix[i]>='a' && infix[i]<='z') || (infix[i]>='A') && (infix[i]<='Z'))
		postfix+=infix[i];
	}
	
	while(!s.empty())
	{
	    char temp=s.top();
		s.pop();
		postfix+=temp;
	}

	return postfix;
}


int main()
{
	cout<<infix_to_postfix("(~(pV(q>(~p)))^r)");
}
