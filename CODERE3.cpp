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
 
 
class CODERE3
{
public:
	
	int Solve(vector<int> sequence, int* DP);
};
 
int mymax(int a, int b){
 
	if (a > b)
	{
		return a;
	}
	return b;
}
 
int CODERE3::Solve(vector<int> sequence, int* DP){
 
	// DP = new int[sequence.size()];
	for (int i = 0; i < sequence.size(); ++i)
	{
		DP[i] = 1;
	}
 
	for (int i = 0; i < sequence.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (sequence[i] > sequence[j])
			{
				DP[i] = mymax(DP[i], 1+DP[j]);
			}
		}
	}
 
	// for (int i = 0; i < sequence.size(); ++i)
	// {
	// 	cout << DP[i] << " ";
	// }
 
}
 
 
int main(int argc, char const *argv[])
{
 
 
	int testcases, x, n;
	scanf("%d", &testcases);
 
	for (int tc = 0; tc < testcases; ++tc)
	{
		CODERE3 mach;
		scanf("%d", &n);
		vector<int> vecc;
 
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			vecc.push_back(x);
		}
 
	    int* DPF = new int[vecc.size()];
		int* DPB = new int[vecc.size()];
		
 
		mach.Solve(vecc, DPF);
		// for (int i = 0; i < vecc.size(); ++i)
		// {
		// 	cout << DPF[i] << " ";
		// }
		// cout << endl;
 
	    std::reverse(vecc.begin(), vecc.end());
		mach.Solve(vecc, DPB);
		// for (int i = 0; i < vecc.size(); ++i)
		// {
		// 	cout << DPB[i] << " ";
		// }
 
		int answer = 0;
		for (int i = 0; i < vecc.size(); ++i)
		{
			answer = mymax(answer, DPF[i] + DPB[vecc.size() - 1 - i] - 1);
		}
 
		cout << answer << endl;	
	}
 
 
 
	return 0;
} 