#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
std::string myreplace(std::string &s,
                      const std::string &toReplace,
                      const std::string &replaceWith)
{
    return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
}
 
void SplitString(const std::string &s, char delim, std::vector<std::string> &elems) {
 
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return;
	
}
 
 
int mymax(int a, int b){
 
	if (a > b)
	{
		return a;
	}
	return b;
}
 
class ACMAKER
{
public:
	int Solve(vector<string> line, string accr);
};
 
int ACMAKER::Solve(vector<string> line, string accr){
 
	int*** DP = new int**[accr.length()];
	for (int i = 0; i < accr.length(); ++i)
	{
		DP[i] = new int*[line.size()];
		for (int j = 0; j < line.size(); ++j)
		{
			DP[i][j] = new int[line[j].length()];
			for (int k = 0; k < line[j].length(); ++k)
			{
				DP[i][j][k] = 0;
			}
		}
	}
 
 
	for (int i = 0; i < accr.length(); ++i)
	{
		for (int j = 0; j < line.size(); ++j)
		{
			for (int k = 0; k < line[j].length(); ++k)
			{
				string word = line[j];
				if (i == 0 && j == 0)
				{
					if (k == 0)
					{
 
						DP[i][j][k] = (accr[i] == word[k]) ? 1 : 0 ;
					}
					else if (accr[i] == word[k])
					{
						DP[i][j][k] = DP[i][j][k-1]+1 ;
					}
					else
					{
						DP[i][j][k] = DP[i][j][k-1] ;						
					}
				}
				else if (accr[i] == word[k])
				{
					int lastAclastWord = (i > 0 && j > 0) ? DP[i-1][j-1][line[j-1].length()-1] : 0;
					int lastAcrCurrWord = (i > 0 && k > 0) ? DP[i-1][j][k-1] : 0;
 
					DP[i][j][k] = (k == 0) ?  lastAclastWord : DP[i][j][k-1] + ( lastAcrCurrWord + lastAclastWord );
				}
				else
				{
					DP[i][j][k] = (k == 0) ? 0 : DP[i][j][k-1];
				}
 
				// cout << DP[i][j][k] << " ";
 
			}
 
			// cout << " : ";
		}
		// cout << endl;
	}
 
	int answer = 0;
			
	for (int k = 0; k < line[line.size()-1].length(); ++k)
	{
		answer = mymax(answer, DP[accr.length()-1][line.size()-1][k]);
	}
	return answer;
}
 
 
int main(int argc, char const *argv[])
{
 
	while(1){
		int N; string str;
		// cin >> N;
		getline(cin, str);
		stringstream ss(str);
 
		ss >> N;
 
		if (N == 0)
		{
			break;
		}
		
		vector<string> vecInsig;
		for (int i = 0; i < N; ++i)
		{
			// cin >> str;
			getline(cin, str);
			stringstream ss(str);
			string out;
			ss >> out;
			// cout << "(" << out << ")" << endl;
			vecInsig.push_back(out);	
			// cout << "(" << str << ")" << endl;
		}
 
 
		string line;
		while(std::getline(std::cin, line)){
			if (line.find("LAST CASE") != std::string::npos)
			{
				break;
			}
			// cout << line << endl;
 
			vector<string> vecLine;
			// SplitString(line, ' ', vecLine);
			stringstream ss(line); string out;
			while(ss >> out){
				vecLine.push_back(out);
			}
			
			string accr = vecLine[0];
 
			vector<string> finalVecLine;
			for (int i = 1; i < vecLine.size(); ++i)
			{
				bool insig = false;
				for (int j = 0; j < vecInsig.size(); ++j)
				{
 
					if (vecLine[i] == vecInsig[j] || vecLine[i].empty())
					{
						insig = true;
					}
				}
				if (!insig)
				{
					finalVecLine.push_back(vecLine[i]);
				}
			}
 
			// for (int i = 0; i < finalVecLine.size(); ++i)
			// {
			// 	cout << "(" << finalVecLine[i] << ")" << endl;
			// }
			string accr2 = accr;
			for (int i = 0; i < accr.length(); ++i)
			{
				accr2[i] += 32;
			}
 
			ACMAKER mach;
			// cout << accr << endl;
			int answer = mach.Solve(finalVecLine, accr2);
 
			if (answer == 0)
			{
				cout << accr << " is not a valid abbreviation\n";
			}
			else
			{
				cout << accr << " can be formed in " << answer << " ways\n";
			}
 
		}
 
	}
 
	return 0;
} 