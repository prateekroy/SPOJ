#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;
typedef long long LL;

LL countways(vector<vector<int>>& gifts, int start, int N)
{
	if(start < gifts.size() && N < 0)return -1; 
	if(start == gifts.size() && N != 0)return -1;
	if(start == gifts.size() && N == 0)return 1;

	LL count = 0;

	for(int j = gifts[start][0]; j <= gifts[start][1]; ++j)
	{
		int ret = countways(gifts, start+1, N-j);
		if(ret != -1)count += ret;
	}
	
	return count;
}

int main(int argc, char const *argv[])
{
    int N, M; cin >> N >> M;
    vector<vector<int>> gifts;
    for(int i = 0; i < N; ++i)
    {
        int a, b; cin >> a >> b;
        gifts.push_back(vector<int>{a, b});
    }
    cout << countways(gifts, 0, M);
    
	
	return 0;
}
