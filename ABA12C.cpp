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
 
class ABA12C
{
public:
 
	int Solve(vector<int> Price, int N, int K);
};
 
int mymin(int a, int b){
	if (a < b)
	{
		return a;
	}
	return b;
}
 
int ABA12C::Solve(vector<int> Price, int N, int K){
 
	int** DP = new int*[K+1];
	for (int i = 0; i < K+1; ++i)
	{
		DP[i] = new int[N+1];
	}
 
	for (int kg = 0; kg < K+1; ++kg)
	{
		for (int no = 0; no < N+1; ++no)
		{
			DP[kg][no] = INT_MAX;
		}
	}
	DP[0][0] = 0;
 
	// for (int no = 0; no < N+1; ++no)
	// {
	// 	DP[0][no] = 0;
	// }
 
	int* DP2 = new int[K+1];
	for (int i = 0; i < K+1; ++i)
	{
		DP2[i] = INT_MAX;
	}
	DP2[0] = 0;
 
	for (int kg = 1; kg < K+1; ++kg)
	{		
		for (int i = 0; i < K; ++i)
		{
			int pickCost = (Price[i] != -1 && kg > i && DP2[kg-i-1] != INT_MAX) ? Price[i] + DP2[kg-i-1] : INT_MAX;
			
			DP2[kg] = mymin(DP2[kg], pickCost);
		}
	}
	return (DP2[K] != INT_MAX) ? DP2[K] : -1;
 
	// for (int kg = 1; kg < K+1; ++kg)
	// {
	// 	for (int no = 1; no < N+1; ++no)
	// 	{
	// 		for (int i = 0; i < K; ++i)
	// 		{
	// 			int pickCost = (Price[i] != -1 && kg > i && DP[kg-i-1][no-1] != INT_MAX) ? Price[i] + DP[kg-i-1][no-1] : INT_MAX;
				
	// 			DP[kg][no] = mymin(DP[kg][no], pickCost);
	// 		}
	// 	}
	// }
 
 
	// for (int kg = 0; kg < K+1; ++kg)
	// {
	// 	for (int no = 0; no < N+1; ++no)
	// 	{
	// 		cout << DP[kg][no] << " ";
	// 	}
	// 	cout << endl;
	// }
 
	// return (DP[K][N] != INT_MAX) ? DP[K][N] : -1;
}
 
 
int main(int argc, char const *argv[])
{
 
	int testcases;
	scanf("%d", &testcases);
	for (int tc = 0; tc < testcases; ++tc)
	{
		int N, K, a;
		vector<int> mv;
		scanf("%d", &N);
		scanf("%d", &K);
		for (int i = 0; i < K; ++i)
		{
			scanf("%d", &a);
			mv.push_back(a);
		}
 
		ABA12C mach;
		printf( "%d\n",mach.Solve(mv, N, K)); 	
	}
 
	return 0;
} 