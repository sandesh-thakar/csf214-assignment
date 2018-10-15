#include<bits/stdc++.h>

using namespace std;


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

struct node* make_parse_tree(string s){

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
	return root
}

int main(){

	string postfix="pqp~>V~r^";

	node* root=make_parse_tree(postfix);
	
}