#include <bits/stdc++.h>

/** @brief Contains the functions to convert postfix expression to rooted binary parse tree and a funtion to traverse the parse tree
 */
class InorderTraversal
{
	public:

	/** @brief struct to represent a node of the parse tree
	 */
	struct node{                     
		struct node* parent;
		char val;
		struct node* left_child;
		struct node* right_child;
	};

	/** @brief Intializes a node with a value
	 * @param val value with which the node is to be initialized
	 * @return node initialized with the value 
	 */
	static struct node* newNode(char val) {
	  struct node* node=(struct node*)malloc(sizeof(struct node)); 

	  node->val=val; 
	  node->left_child=NULL; 
	  node->right_child=NULL; 
	  return(node); 
	} 

	/** @brief Converts postfix propostional logic expression to rooted binary parse tree 
	 * and then calls the traversal function 
	 * @param postfix the postfix propositional logic expression
	 * @return Void
	 */
	static void postfix_to_parse_tree(string postfix) 
	{

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
		traverse_parse(root);
	}


	/** @brief Prints the in-order traversal of the parse tree
	 * @param cur the root of the parse tree
	 * @return Void
	 */
	static void traverse_parse(node* cur) 
	{

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
};