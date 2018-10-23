#include <bits/stdc++.h>
using namespace std;

/** @brief Contains the function to convert infix expression to postfix expression
 */
class InfixToPostfix
{
	public: 


	/** @brief Converts infix propostional logic expression to postfix propostional logic expression	
	 * @param infix the infix propositional logic expression
	 * @return the postfix propositional logic expression
	 */
	static string infix_to_postfix(string infix) 
	{
		
		int precedence_index[infix.length()]; //array to store precedence of operators
		
		int level=0;
		
		for(int i=0;i<infix.length();i++)                                         
		{
		    if(infix[i]=='~' || infix[i]=='^' || infix[i]=='V' || infix[i]=='>')
		        precedence_index[i]=level;
		        
		    else if(infix[i]=='(') 
		        level++;
		        
		   else if(infix[i]==')') 
		        level--;
		}

		stack <char> s;

		string postfix=""; //string to store postfix expression

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

};