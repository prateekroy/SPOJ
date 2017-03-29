#include <iostream> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <cmath> 
#include <ctime> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include "limits.h"
 
using namespace std;
 
class Crosscountry
{
public:
 
	int Solve(vector<int> Acheckpoints, vector<int> Bcheckpoints);
};
 
int mymax(int a, int b){
	if (a > b)
	{
		return a;
	}
	return b;
}
 
 
int Crosscountry::Solve(vector<int> Acheckpoints, vector<int> Bcheckpoints){
 
	int**DP = new int*[Acheckpoints.size()];
	for (int i = 0; i < Acheckpoints.size(); ++i)
	{
		DP[i] = new int[Bcheckpoints.size()];
	}
 
 
	for (int i = 0; i < Acheckpoints.size(); ++i)
	{
		for (int j = 0; j < Bcheckpoints.size(); ++j)
		{
			DP[i][j] = INT_MAX;
		}
	}
 
	for (int i = 0; i < Acheckpoints.size(); ++i)
	{
		for (int j = 0; j < Bcheckpoints.size(); ++j)
		{
			int equal = 0;
			if (Acheckpoints[i] == Bcheckpoints[j])
			{
				if ( i>0 && j>0 )
				{
					equal = 1+DP[i-1][j-1];
				}
				else
				{
					equal = 1;
				}
			}
			int last1 = (i > 0) ? DP[i-1][j] : 0;
			int last2 = (j > 0) ? DP[i][j-1] : 0;
			DP[i][j] = mymax(last1, mymax(last2, equal)); 
		}
	}
 
 
 
	return DP[Acheckpoints.size()-1][Bcheckpoints.size()-1];
}
 
 
int main(int argc, char const *argv[])
{
	Crosscountry mach;
	int testcases;
	scanf("%d", &testcases);
	
	
 
	for (int tc = 0; tc < testcases; ++tc)
	{
		int x, a, b;
		vector<int> vecc;
		int answer = 0;
		scanf("%d", &x);
		while (x != 0)
		{
			vecc.push_back(x);
			scanf("%d", &x);			
		}
			
		scanf("%d", &b);
		while(b != 0){
			vector<int> vecs;
			vecs.push_back(b);
			
			scanf("%d", &a);
			while(a != 0){
 
				vecs.push_back(a);
				scanf("%d", &a);
			}
 
 
			// cout << "\n***********************************\n";
			// for (int i = 0; i < vecc.size(); ++i)
			// {
			// 	cout << vecc[i] << " ";
			// }
			// cout << "\n";
			// for (int i = 0; i < vecs.size(); ++i)
			// {
			// 	cout << vecs[i] << " ";
			// }
 
			// cout << "\n***********************************\n";
			answer = mymax(answer, mach.Solve(vecc, vecs));
 
			scanf("%d", &b);
		}
 
		printf("%d\n", answer);
	}
 
 
	// Crosscountry mach;
 
	// int c[] = {1, 2, 1, 1};
 //    int s[] = {1, 1, 1};
 
 //    vector<int> vecc(c, c + sizeof(c) / sizeof(c[0]));
 //    vector<int> vecs(s, s + sizeof(s) / sizeof(s[0]));
 
	// cout << mach.Solve(vecc, vecs);
	return 0;
} 