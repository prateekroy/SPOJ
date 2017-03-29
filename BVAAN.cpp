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
 
class BVAAN
{
public:
	int Solve(string a, string b, int K);
};
 
int mymax(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
 
int BVAAN::Solve(string a, string b, int K){
 
	int*** DP = new int**[a.length()];
	for (int i = 0; i < a.length(); ++i)
	{
		DP[i] = new int*[b.length()];
		for (int j = 0; j < b.length(); ++j)
		{
			DP[i][j] = new int[K+1];
			for (int k = 0; k < K+1; ++k)
			{
				if (k == 0)
				{
					DP[i][j][k] = 0;
				}
				else
				{
					DP[i][j][k] = INT_MIN;
				}
			}
		}
	}
 
 
	for (int i = 0; i < a.length(); ++i)
	{
		for (int j = 0; j < b.length(); ++j)
		{
			for (int k = 1; k < K+1; ++k)
			{
				if (i == 0 && j == 0)
				{
					DP[i][j][1] = (a[i] == b[j]) ? a[i] : INT_MIN;
				}
				else if(i == 0)
				{
					int equal = (a[i] == b[j]) ? a[i] : INT_MIN;
					DP[i][j][1] = mymax(equal, DP[i][j-1][1]);
				}
				else if (j == 0)
				{
					int equal = (a[i] == b[j]) ? a[i] : INT_MIN;
					DP[i][j][1] = mymax(equal, DP[i-1][j][1]);					
				}
				else
				{
					int equal = (a[i] == b[j] && DP[i-1][j-1][k-1] != INT_MIN) ? a[i]+DP[i-1][j-1][k-1] : INT_MIN;
					DP[i][j][k] = mymax(equal, mymax(DP[i-1][j-1][k], mymax(DP[i][j-1][k], DP[i-1][j][k])));
				}
				// cout << DP[i][j][k] << " ";
			}
			// cout << endl;
		}
		// cout << endl;
	}
 
	return (DP[a.length()-1][b.length()-1][K] != INT_MIN) ? DP[a.length()-1][b.length()-1][K] : 0;
}
 
 
int main(int argc, char const *argv[])
{
	
	int testcases;
	scanf("%d", &testcases);
	for (int tc = 0; tc < testcases; ++tc)
	{
		BVAAN mach;
		string a, b;
		int K;
		// scanf("%s", &a);
		// scanf("%s", &b);
		cin >> a >> b;
		scanf("%d", &K);
 
		cout << mach.Solve(a, b, K) << endl;
	}
	return 0;
}