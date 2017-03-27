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
typedef long long LL;
 
class BLKEK
{
public:
	LL Solve(string a);
};
 
LL BLKEK::Solve(string a){
 
	int* DP = new int[a.length()];
 
	int countK = 0; 
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] == 'K')
		{
			countK++;
		}
 
		DP[i] = countK;
	}
 
	int answer = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] == 'E')
		{
			answer += DP[i] * (countK-DP[i]);
		}
	}
 
	return answer;
}
 
 
int main(int argc, char const *argv[])
{
	BLKEK mach;
	int testcases;
	scanf("%d", &testcases);
 
	for (int tc = 0; tc < testcases; ++tc)
	{
		string s;
		cin >> s;
		cout << mach.Solve(s) << endl;		
	}
 
	return 0;
} 