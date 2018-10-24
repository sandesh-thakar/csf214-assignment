#include<bits/stdc++.h>

using namespace std;

bool and_intro(string lines[], int line1, int line2, int calling_line) // for checking and introduction
{
	/* In And Introduction:
		lines[] = the set of previous lines in the proof (without the rules)
		line1 = the line number of the LHS of the ^ which is to be introduced
		line2 = the line number of the RHS of the ^ which is to be introduced
		calling_line = the current line from where the rule is called
	*/
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

bool and_elim(string lines[], int type, int ref_line, int calling_line)
{
	/* In And Elimination:
		lines[] = the set of previous lines in the proof (without the rules)
		type = or introduction 1 or 2
		ref_line = The line on which and elimination is being applied
		calling_line = the current line from where the rule is called
	*/
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

bool or_intro(string lines[], int type, int ref_line, int calling_line)
{
	/*In Or Introduction:
		lines[] = the set of previous lines in the proof (without the rules)
		type = or introduction 1 or 2
		ref_line = The line on which or introduction is being applied
		calling_line = the current line from where the rule is called
	*/
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

bool implies_elim(string lines[],int line1,int line2,int calling_line)
{
/* In Implication Elimination:
	lines[] = the set of previous lines in the proof (without the rules)
	line1 = 
	line2 = 
	calling_line = the current line from where the rule is called
*/
	
	string phi_implies_psi=lines[line1];
	string phi=lines[line2];
	string psi=lines[calling_line];

	string test="("+phi+">"+psi+")";
	
	

	if(phi_implies_psi.compare(test)==0)
		return true;

	else 
		return false;
}

bool is_valid_proof(int no_of_lines) // The interface function for testing the entire proof
{
	string lines[no_of_lines+1];
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
					valid = and_intro(lines, line1, line2, i);
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
					valid = and_elim(lines, type, ref_line, i);
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
				valid = or_intro(lines, type, ref_line, i);
		}
		else if(line[rule_end+1] == '>')
		{
		    
		    
			int ref_line1 = line[rule_end+4] - '0';
			int ref_line2 = line[rule_end+6] - '0';
			if(ref_line1>=i || ref_line2>=i)
			{
				valid = false;
				continue;
			}
			else
				valid = implies_elim(lines, ref_line1, ref_line2, i);
		}
	}
	if(valid)
		return true;
	else
		return false;
}

int main()
{
    /*#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif*/
    int n;
    cin >> n;
    if(is_valid_proof(n))
    	cout << "Valid Proof\n";
    else
    	cout << "Invalid Proof\n";
}
