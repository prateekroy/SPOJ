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
#include <stdio.h>
using namespace std;
 
 
int bin_search(vector<int> _time, int b){
 
   int low = 0;
   int high = _time.size() - 1;
   while (low <= high) {
       int mid = low + ((high - low) / 2);
       if (_time[mid] > b)
           high = mid - 1;
       else if (_time[mid] < b)
           low = mid + 1;
       else
           return mid; // found
   }
   return -1; // not found
}
 
 
 
bool TryFor(vector<int> sheds, int dist, int C){
 
	// cout << sheds.size() << " " << dist << " " << C << endl;
	int cowsPlaced = 0;
 
	int prev = sheds[0];
	for (int shed = 1; shed < sheds.size(); ++shed)
	{
		if( sheds[shed] - prev >= dist ){
			prev = sheds[shed];
			cowsPlaced++;
			// cout << "cowsPlaced : " << cowsPlaced << endl;
		}
 
		if (cowsPlaced == C-1)
		 {
		 	return true;
		 } 
	}
 
	return false;
 
}
 
int findSolution(vector<int> sheds, int max, int min, int C){
 
 
	int start=0,end=max-min,mid;
 
	while(end-start > 1)
	{
	  mid=(end+start)>>1;
 
	  if (TryFor(sheds, mid, C))
	  {
	  	start = mid;
	  }
	  else
	  {
	  	end = mid;
	  }
 
	}
 
	return start;
 
}
 
 
 
int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
 
	for (int tc = 0; tc < testcases; ++tc)
	{
		int N, C;
		cin >> N >> C;
 
		int max = INT_MIN; int min = INT_MAX;
		int x; vector<int> sheds;
		for (int i = 0; i < N; ++i)
		{
			cin >> x;
			if (x > max)
			{
				max = x;
			}
 
			if (x < min)
			{
				min = x;
			}
 
			sheds.push_back(x);
		}
 
		// cout << max << " " << min << endl;
 
		std::sort(sheds.begin(), sheds.end());
 
		cout << findSolution(sheds, max, min, C) << endl;
 
		// for (int trys = 1; trys < (max-min); ++trys)
		// {
		// 	if (TryFor(sheds, trys, C))
		// 	{
		// 		//cout << trys-1 << endl;
		// 		// break;
		// 		continue;
		// 	}
		// 	else
		// 	{
		// 		cout << trys-1 << endl;
		// 		break;
		// 	}
		// }
	}
	return 0;
} 