#include<bits/stdc++.h>
#include "proof.h"

using namespace std;

/**Proof Checker project
 */
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	bool ch=true;
	cout << "Welcome to the Proof Checker!\n\nWould you like to check a proof? Enter y/n:\n";
	char x;
	cin >> x;
	if(x!='y')
		ch=false;
	while(ch)
	{
		
		int no_of_lines; 
		cout << "\n";
		cout << "Enter number of lines:\n";
		cin >> no_of_lines;
		Proof p(no_of_lines);
		cout << "Enter all " << no_of_lines << " lines of the proof:\n";
		cout << "\n";
		if(p.check())
			cout << "Valid Proof\n";
		else
			cout << "Invalid Proof\n";
		cout << "\n";
		cout << "Would you like to check another proof?\nEnter y/n:\n";
		cin >> x;
		if(x!='y')
			ch=false;
	}	
	cout << "\n";
	cout << "Thanks for using our proof checker!";
}