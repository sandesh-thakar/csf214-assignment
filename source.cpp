#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;


//Infix propositional logic expression to postfix propositional logic expression
string infix_to_postfix(string infix)  
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


//Postfix propositional logic expression to rooted binary parse tree
struct node{
	struct node* parent;
	char val;
	struct node* left_child;
	struct node* right_child;
};

struct node* newNode(char val) {
  struct node* node=(struct node*)malloc(sizeof(struct node)); 

  node->val=val; 
  node->left_child=NULL; 
  node->right_child=NULL; 
  return(node); 
} 

struct node* postfix_to_parse_tree(string postfix){

	stack<node*>st;

	int n=postfix.size();

	for(int i=0;i<n;i++){
		char ch=postfix[i];
		node* cur=newNode(ch);

		//unary operator
		if(ch=='~'){

			node* left=st.top();
			st.pop();
			left->parent=cur;

			cur->left_child=left;
			st.push(cur);
		}

		//binary operator
		else if(ch=='^' || ch=='V' || ch=='>'){

			node* left=st.top();
			st.pop();
			left->parent=cur;

			node* right=st.top();
			st.pop();
			right->parent=cur;

			cur->left_child=left;
			cur->right_child=right;
			st.push(cur);
		}

		//propositional atom
		else{
			st.push(cur);
		}
	}

	node* root = st.top();
	return root;
}


//In-order traversal of rooted binary parse tree
void traverse_parse(node* cur){

	if(cur==NULL){
		return;
	}

	node* left=cur->left_child;
	node* right=cur->right_child;

	bool isatom=!(left==NULL && right==NULL);
	if(isatom)cout<<'(';
    traverse_parse(right);
    cout<<cur->val;
	traverse_parse(left);
	if(isatom)cout<<')';
}

int main()
{
	
}
