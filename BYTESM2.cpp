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
class BYTESM2
{
public:
	int Solve(int** Matrix, int X, int Y);
};
 
int mymax(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
 
int BYTESM2::Solve(int** Matrix, int X, int Y){
 
	int** DP = new int*[X];
	for (int i = 0; i < X; ++i)
	{
		DP[i] = new int[Y];
	}
 
	for (int i = 0; i < Y; ++i)
	{
		DP[X-1][i] = Matrix[X-1][i];
	}
 
	for (int i = X-2; i >= 0; --i)
	{
		for (int j = 0; j < Y; ++j)
		{
			int option1 = (j < Y-1) ? DP[i+1][j+1] : 0;
			int option2 = (j > 0) ? DP[i+1][j-1] : 0;
			DP[i][j] = mymax(Matrix[i][j]+DP[i+1][j], mymax(Matrix[i][j]+option1, Matrix[i][j]+option2));
		}
	}
 
 
	// for (int i = 0; i < X; ++i)
	// {
	// 	for (int j = 0; j < Y; ++j)
	// 	{
	// 		cout << DP[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
 
	// cout << endl;
 
	int answer = 0;
	for (int i = 0; i < Y; ++i)
	{
		answer = mymax(answer, DP[0][i]);
	}
	return answer;
}
 
 
int main(int argc, char const *argv[])
{
	int testcases;
	scanf("%d", &testcases);
	for (int tc = 0; tc < testcases; ++tc)
	{
		int x, y, a;
		BYTESM2 mach;
		scanf("%d", &x);
		scanf("%d", &y);
		int** Mat = new int*[x];
		for (int i = 0; i < x; ++i)
		{
			Mat[i] = new int[y];
		}
 
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				scanf("%d", &a);
				Mat[i][j] = a;
			}
		}
 
		cout << mach.Solve(Mat, x, y) << endl;
	}
 
 
	return 0;
} 