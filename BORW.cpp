#include <iostream>
#include <vector>
#include "limits.h"
using namespace std;
 
int mymax(int a, int b){
	if (a > b)
	{
		return a;
	}
	return b;
}
 
int mymin(int a, int b){
	if (a < b)
	{
		return a;
	}
	return b;
}
 
vector<int> incArray;
vector<int> decArray;
 
int DP[201][201];
 
void init(){
 
	incArray.clear();
	decArray.clear();
 
	incArray.push_back(0);
	decArray.push_back(INT_MAX);
 
	for (int i = 0; i < 201; ++i)
	{
		for (int j = 0; j < 201; ++j)
		{
			DP[i][j] = INT_MAX;
		}
	}
 
	DP[0][0] = 0;
}
 
int Solve(){
 
	for (int i = 0; i < incArray.size(); ++i)
	{
		for (int j = 0; j < incArray.size(); ++j)
		{
			if (i == j && i != 0 && j != 0)
			{
				continue;
			}
 
			for (int row = 0; row < i; ++row)
			{
				if (incArray[i] > incArray[row] && DP[row][j] != INT_MAX)
				{
					if (i-mymax(row,j) > 0)
					{
						DP[i][j] = mymin(DP[i][j], DP[row][j]+i-mymax(row,j)-1);
					}
					else if (i-mymax(row,j) == 0)
					{
						DP[i][j] = mymin(DP[i][j], DP[row][j]+i-mymax(row,j));
					}
					
				}
			}
 
			for (int col = 0; col < j; ++col)
			{
				if (decArray[j] < decArray[col] && DP[i][col] != INT_MAX)
				{
					if (j-mymax(col,i) > 0)
					{
						DP[i][j] = mymin(DP[i][j], DP[i][col]+j-mymax(col,i)-1);
					}
					else if (j-mymax(col,i) == 0)
					{
						DP[i][j] = mymin(DP[i][j], DP[i][col]+j-mymax(col,i));
					}					
				}
			}
		}
	}
 
	// for (int i = 0; i < incArray.size(); ++i)
	// {
	// 	for (int j = 0; j < incArray.size(); ++j)
	// 	{
	// 		cout << DP[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
 
	int answer = INT_MAX;
	for (int i = 0; i < incArray.size(); ++i)
	{
		answer = mymin(answer, mymin(DP[i][incArray.size()-1], DP[incArray.size()-1][i]));
	}
 
	for (int i = 0; i < incArray.size(); ++i)
	{
		for (int j = 0; j < incArray.size(); ++j)
		{
			if(incArray.size()-mymax(i,j) > 1 && DP[i][j] != INT_MAX){
				answer = mymin(answer, DP[i][j]+incArray.size()-1-mymax(i,j));
			}
			// cout << answer << " ";			
		}
		// cout << endl;
	}
 
	return answer;
 
}
 
 
int main(int argc, char const *argv[])
{
	
 
	int N, x;
	cin >> N;
	while(N != -1){
		init();
		for (int i = 0; i < N; ++i)
		{
			cin >> x;
			incArray.push_back(x);
			decArray.push_back(x);
		}
 
		cout << Solve() << endl;
 
		cin >> N;
	}
 
	return 0;
}