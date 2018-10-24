#ifndef proof
#define proof

#include<bits/stdc++.h>
#include "andintroduction.h"
#include "andelimination.h"
#include "orintroduction.h"
#include "implieselimination.h"

using namespace std;

class Proof
{
	int no_of_lines;
	public:
		/** @brief constructor for the class
		 */
		Proof(int no_of_lines)
		{
			this->no_of_lines = no_of_lines;
		}
		/** @brief checks the validity of the proof
		* @return true if the proof is valid and false if it is invalid 
		 */
		bool check()
		{
			vector<string>lines(no_of_lines+1,"");
			bool valid = true;
			cin.ignore();
			for(int i = 1;i <= no_of_lines;i++)
			{
				string line;
				getline(cin, line);
				//cerr << line << "\n";
				if(!valid)
					continue;
				int rule_end;
				for(int j = 0;j < line.length(); j++)
				{
					if(line[j] == '/')
					{
						rule_end = j;
						break;
					}
				}
				string rule = line.substr(0,rule_end);
				//cerr << rule_end << "\n";
				lines[i] = rule;
				if(line[rule_end+1] == 'P')
					continue;
				else if(line[rule_end+1] == '^')
				{
					if(line[rule_end+2] == 'i')
					{
						int line1 = line[rule_end+4] - '0';
						int line2 = line[rule_end+6] - '0';
						//cerr << line1 << " " << line2 << "\n";
						if(line1 >= i || line2 >= i)
						{
							valid = false;
							continue;
						}
						else
						{
							AndIntroduction a(lines,line1,line2,i);
							valid = a.check();
						}
					}
					else
					{
						int type = line[rule_end+3] - '0';
						int ref_line = line[rule_end+5] - '0';
						//cerr << type << " " << ref_line << "\n";
						if(ref_line>=i)
						{
							valid = false;
							continue;
						}
						else
						{
							AndElimination a(lines,type,ref_line,i);
							valid = a.check();
						}
					}
				}
				else if(line[rule_end+1] == 'V')
				{
					int type = line[rule_end+3] - '0';
					int ref_line = line[rule_end+5] - '0';
					if(ref_line>=i)
					{
						valid = false;
						continue;
					}
					else
					{
						OrIntroduction a(lines,type,ref_line,i);
						valid = a.check();
					}
				}
				else if(line[rule_end+1] == '>')
				{
					int line2 = line[rule_end+4] - '0';
					int line1 = line[rule_end+6] - '0';
					if(line1>=i||line2>=i)
					{
						valid = false;
						continue;
					}
					else
					{
						ImpliesElimination a(lines,line1,line2,i);
						valid = a.check();
					}
				}
			}
			if(valid)
				return true;
			else
				return false;
		}
};

#endif