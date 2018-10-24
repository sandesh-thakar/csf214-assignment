#ifndef orintroduction
#define orintroduction

#include<bits/stdc++.h>

using namespace std;

class OrIntroduction
{
	vector<string>lines;
	int type;
	int ref_line;
	int calling_line;
	public:

		/** @brief constructor for the class
		 */
		OrIntroduction(vector<string>lines,int type,int ref_line,int calling_line)
		{
			this->lines = lines;
			this->type = type;
			this->ref_line = ref_line;
			this->calling_line = calling_line;
		}
		/** @brief checks validity of statements obtained by or introduction rule
		 * @return  whether the or introduction rule is used correctly
		 */
		bool check()
		{
			if(lines[ref_line].length()+4>lines[calling_line].length())
				return false;
			if(lines[calling_line][0]!='('||lines[calling_line][lines[calling_line].length()-1]!=')')
				return false;
			if(type==1)
			{
				string seq=lines[ref_line];
				string cmp=lines[calling_line].substr(1,seq.length());
				if(seq.compare(cmp)!=0)
					return false;
				if(lines[calling_line][seq.length()+1]!='V')
					return false;
				return true;
			}
			else
			{
				string seq=lines[ref_line];
				string cmp=lines[calling_line].substr(lines[calling_line].length()-seq.length()-1,seq.length());
				if(seq.compare(cmp)!=0)
					return false;
				if(lines[calling_line][lines[calling_line].length()-seq.length()-2]!='V')
					return false;
				return true;
			}
		}
};

#endif