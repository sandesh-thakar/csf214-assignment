#include<bits/stdc++.h>
#include "proof.h"

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	bool ch=true;
	do
	{
		cout << "Welcome to the Proof Checker!\n\nWould you like to check a proof? Enter y/n:\n";
		char x;
		cin >> x;
		if(x!='y')
		{
			ch=false;
			break;
		}
		int no_of_lines;
		cout << "Enter number of lines:\n";
		cin >> no_of_lines;
		Proof p(no_of_lines);
		cout << "Enter all " << no_of_lines << " lines of the proof:\n";
		if(p.check())
			cout << "Valid Proof\n";
		else
			cout << "Invalid Proof\n";
		cout << "Would you like to check another proof?\nEnter y/n:\n";
		cin >> x;
		if(x!='y')
			ch=false;
	} while (ch);	
	cout << "Thanks for using our proof checker!";
}