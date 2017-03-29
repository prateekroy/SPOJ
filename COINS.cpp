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
#include <time.h>
using namespace std;
 
typedef long long LL;
 
 
LL mymax(LL a, LL b){
	if (a > b)
	{
		return a;
	}
	return b;
}
 
static double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
    return diffms;
}
 
class COINS
{
public:
	LL* DP;
	void Solve();
	LL Query(LL a);
	map<LL, LL> mmap;
	LL QueryMap(LL a);
};
 
 
void COINS::Solve(){
	// DP = new LL[1000000001];
 
	// for (LL i = 0; i < 1000000001; ++i)
	// {
	// 	DP[i] = 0;
	// 	DP[i] = mymax(i, DP[i/2] + DP[i/3] + DP[i/4]);
	// }
 
	mmap[0] = 0;
}
 
LL COINS::Query(LL a){
	return DP[a];
}
 
LL COINS::QueryMap(LL a){
	if (mmap.find(a) != mmap.end())
	{
		return mmap[a];		
	}
	else
	{
		LL result = mymax(a, QueryMap(a/2) + QueryMap(a/3) + QueryMap(a/4));
		mmap[a] = result;
		return result;
	}
}
 
 
 
int main(int argc, char const *argv[])
{
 
	LL n;
	COINS mach;
	// clock_t clock1 = clock()
	mach.Solve();
	// clock_t clock2 = clock();
	// cout << diffclock(clock2, clock1);
	while( scanf("%lld", &n) != EOF){
 
		cout << mach.QueryMap(n) << endl;
	}
 
 
 
	
	return 0;
}