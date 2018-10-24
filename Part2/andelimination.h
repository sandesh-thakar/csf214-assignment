#ifndef andelimination
#define andelimination

#include<bits/stdc++.h>

using namespace std;

class AndElimination
{
	vector<string>lines;
	int type;
	int ref_line;
	int calling_line;
	public:

		/** @brief constructor for the class
		 */

		AndElimination(vector<string>lines,int type,int ref_line,int calling_line)
		{
			this->lines = lines;
			this->type = type;
			this->ref_line = ref_line;
			this->calling_line = calling_line;
		}

		/** @brief checks validity of statements obtained by and elimination rule
		 * @return  whether the and elimination rule is used correctly
		 */
		bool check()
		{
			if(lines[ref_line].length()<lines[calling_line].length()+4)
				return false;
			if(lines[ref_line][0]!='('||lines[ref_line][lines[ref_line].length()-1]!=')')
				return false;
			if(type == 1)
			{
				string seq = lines[calling_line];
				string cmp = lines[ref_line].substr(1,seq.length());
				if(seq.compare(cmp)!=0)
					return false;
				if(lines[ref_line][seq.length()+1]!='^')
					return false;
				return true;
			}
			else
			{
				string seq = lines[calling_line];
				string cmp = lines[ref_line].substr(lines[ref_line].length()-seq.length()-1,seq.length());
				if(seq.compare(cmp)!=0)
					return false;
				if(lines[ref_line][lines[ref_line].length()-seq.length()-2]!='^')
					return false;
				return true;
			}
		}
};

#endif