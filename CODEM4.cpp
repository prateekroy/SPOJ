#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;
typedef long long LL;

int canWin(vector<int> score, int s, int e, vector<vector<int>>& dp)
{
	if(s > e)return 0;
	if(dp[s][e] != INT_MAX)return dp[s][e];

	int diff = score[s] - canWin(score, s+1, e, dp);
	diff = max(diff, score[e] - canWin(score, s, e-1, dp));
	return dp[s][e] = diff;
}

int canWinDumb(vector<int> score, int s, int e, bool turn, vector<vector<int>>& dp)
{
	if(s > e)return 0;
	if(dp[s][e] != INT_MAX)return dp[s][e];

	int diff = score[s] - canWinDumb(score, s+1, e, !turn, dp);
	if(turn)diff = max(diff, score[e] - canWinDumb(score, s, e-1, !turn, dp));
	else diff = min(diff, score[e] - canWinDumb(score, s, e-1, !turn, dp));

	return dp[s][e] = diff;
}

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for(int tc = 0; tc < testcases; ++tc){
		vector<int> score;
		int n, num, sum; cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> num;
			score.push_back(num);
			sum += num;
		}
		
		vector<vector<int>> dp(score.size(), vector<int>(score.size(), INT_MAX));
		vector<vector<int>> dp2(score.size(), vector<int>(score.size(), INT_MAX));
		cout << (sum + canWin(score, 0, score.size()-1, dp))/2 << " " << (sum + canWinDumb(score, 0, score.size()-1, true, dp2))/2 << endl;
	}
	return 0;
}
