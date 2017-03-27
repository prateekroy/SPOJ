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
 
class BCAKE
{
public:
	int Solve(char** Cake, int sizeX, int sizeY, int K);
	int findMinArea(char** Cake, int sizeX, int sizeY, int startPointX, int startPointY, int K);
};
 
int mymin(int a, int b){
	if (a < b)
	{
		return a;
	}
	return b;
}
 
int BCAKE::findMinArea(char** Cake, int sizeX, int sizeY, int startPointX, int startPointY, int K){
 
	int** DP = new int*[sizeX];
	for (int i = 0; i < sizeX; ++i)
	{
		DP[i] = new int[sizeY];
	}
 
	for (int i = 0; i < sizeX; ++i)
	{
		for (int j = 0; j < sizeY; ++j)
		{
			DP[i][j] = 0;		
		}
	}
 
	int minarea = INT_MAX;
 
	for (int i = startPointX; i < sizeX; ++i)
	{
		for (int j = startPointY; j < sizeY; ++j)
		{
			int current = (Cake[i][j] == 'C') ? 1 : 0;
			int up = (i > 0) ? DP[i-1][j] : 0;
			int down = (j > 0) ? DP[i][j-1] : 0;
			int extra = (i > 0 && j > 0) ? DP[i-1][j-1] : 0;
			DP[i][j] = up + down - extra + current;
 
			if (DP[i][j] == K)
			{
				minarea	= mymin(minarea, (i-startPointX+1)*(j-startPointY+1));
			}
		}
	}
 
	// for (int i = 0; i < sizeX; ++i)
	// {
	// 	for (int j = 0; j < sizeY; ++j)
	// 	{
	// 		cout << DP[i][j] << " ";		
	// 	}
	// 	cout << endl;
	// }
 
	return minarea;
}
 
 
int BCAKE::Solve(char** Cake, int sizeX, int sizeY, int K){
 
	int answer = INT_MAX;
	for (int i = 0; i < sizeX; ++i)
	{
		for (int j = 0; j < sizeY; ++j)
		{
			answer = mymin(answer, findMinArea(Cake, sizeX, sizeY, i, j, K));
		}
	}
 
	return (answer != INT_MAX) ? answer : -1;
}
 
 
int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int tc = 0; tc < testcases; ++tc)
	{
		BCAKE mach;
		int x, y, k;
		char a;
		cin >> x >> y >> k;
		char** cake = new char*[x];
		for (int i = 0; i < x; ++i)
		{
			cake[i] = new char[y];
		}
 
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				cin >> a;
				cake[i][j] = a;
			}
		}
		cout << mach.Solve(cake, x, y, k) << endl;
	}
 
 
	return 0;
}