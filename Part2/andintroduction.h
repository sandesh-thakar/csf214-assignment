#ifndef andintroduction
#define andintroduction

#include<bits/stdc++.h>

using namespace std;

class AndIntroduction
{
	vector<string>lines;
	int line1;
	int line2;
	int calling_line;
	public:
		AndIntroduction(vector<string>lines,int line1,int line2,int calling_line)
		{
			this->lines = lines;
			this->line1 = line1;
			this->line2 = line2;
			this->calling_line = calling_line;
		}
		bool check() 
		{
			
			if(lines[calling_line].length()!=lines[line1].length() + lines[line2].length() +3)
				return false;
			if(lines[calling_line][0]!='('||lines[calling_line][lines[calling_line].length()-1]!=')')
				return false;
			string seq1 = lines[line1];
			string seq2 = lines[line2];
			string cmp = lines[calling_line].substr(1, seq1.length());
			if(seq1.compare(cmp)!=0)
				return false;
			if(lines[calling_line][seq1.length()+1]!='^')
				return false;
			cmp = lines[calling_line].substr(seq1.length()+2, seq2.length());
			if(seq2.compare(cmp)!=0)
				return false;
			return true;
		}
};

#endif