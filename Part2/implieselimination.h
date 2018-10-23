#ifndef implieselimination
#define implieselimination

#include<bits/stdc++.h>

using namespace std;

class ImpliesElimination
{
	vector<string>lines;
	int line1;
	int line2;
	int calling_line;
	public:
		ImpliesElimination(vector<string>lines,int line1,int line2,int calling_line)
		{
			this->lines = lines;
			this->line1 = line1;
			this->line2 = line2;
			this->calling_line = calling_line;
		}
		bool check()
		{
			string phi=lines[line1];
			string phi_implies_psi=lines[line2];
			string psi=lines[calling_line];

			string test="("+phi+">"+psi+")";

			if(phi_implies_psi.compare(test)==0)
				return true;

			else 
				return false;
		}
};
#endif