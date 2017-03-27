#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;
 
class ADFRUITS
{
public:
 
	string Solve(string a, string b);
	
};
 
 
string ADFRUITS::Solve(string a, string b){
 
	int*** DP = new int**[a.length()+1];
	for (int i = 0; i <= a.length(); ++i)
	{
		DP[i] = new int*[b.length()+1];
		for (int j = 0; j < b.length()+1; ++j)
		{
			DP[i][j] = new int[5];
			for (int k = 0; k < 5; ++k)
			{
				DP[i][j][k] = 0;
			}
		}
	}
 
	string** sDP = new string*[a.length()+1];
	for (int i = 0; i < a.length()+1; ++i)
	{
		sDP[i] = new string[b.length()+1];
		for (int j = 0; j < b.length()+1; ++j)
		{
			sDP[i][j] = "";
		}
	}
 
 
	for (int i = 1; i <= a.length(); ++i)
	{
		for (int j = 1; j < b.length()+1; ++j)
		{
 
			if (a[i-1] == b[j-1] && 1+DP[i-1][j-1][0] > DP[i][j][0])
			{
				DP[i][j][0] = 1+DP[i-1][j-1][0];
				sDP[i][j] = sDP[i-1][j-1];
				if (DP[i-1][j-1][1] == 0 || DP[i-1][j-1][2] == 0 || DP[i-1][j-1][3] == 0 || DP[i-1][j-1][4] == 0)
				{
					// cout << i << "~~" << j << endl;
					DP[i][j][1] = i;DP[i][j][2] = i;
					DP[i][j][3] = j;DP[i][j][4] = j; 
				}	
				else
				{
					// cout << i << "!~~" << j << endl;
					for (int k = DP[i-1][j-1][2]; k < i-1; ++k)
					{
						sDP[i][j] += a[k];
					}
					for (int k = DP[i-1][j-1][4]; k < j-1; ++k)
					{
						sDP[i][j] += b[k];
					}
					DP[i][j][1] = DP[i-1][j-1][1];
					DP[i][j][2] = i;
					DP[i][j][3] = DP[i-1][j-1][3];
					DP[i][j][4] = j;
				}
				sDP[i][j] += a[i-1];
			}
 
			if (DP[i][j-1][0] > DP[i][j][0])
			{
				DP[i][j][0] = DP[i][j-1][0];
				sDP[i][j] = sDP[i][j-1];
 
				for (int k = 1; k < 5; ++k)
				{
					DP[i][j][k] = DP[i][j-1][k];
				}				
			}
 
			if (DP[i-1][j][0] > DP[i][j][0])
			{
				DP[i][j][0] = DP[i-1][j][0];
				sDP[i][j] = sDP[i-1][j];
 
				for (int k = 1; k < 5; ++k)
				{
					DP[i][j][k] = DP[i-1][j][k];
				}
			}
		}
	}
 
	// cout << sDP[a.length()][b.length()] << endl;
 
	// cout << DP[a.length()][b.length()][1] << " - " << DP[a.length()][b.length()][2] << endl;	
	// cout << DP[a.length()][b.length()][3] << " - " << DP[a.length()][b.length()][4] << endl;	
 
 
	string answer="";
 
	for (int i = 0; i < DP[a.length()][b.length()][1]-1; ++i)
	{
		answer += a[i];
	}
	for (int i = 0; i < DP[a.length()][b.length()][3]-1; ++i)
	{
		answer += b[i];
	}
 
	string common = sDP[a.length()][b.length()];
	// if (DP[a.length()][b.length()][1] > 0 && DP[a.length()][b.length()][2] > 0 && DP[a.length()][b.length()][3] > 0 && DP[a.length()][b.length()][4] > 0)
	// {	
	// 	common += a[DP[a.length()][b.length()][1]-1];
	// 	for (int i = DP[a.length()][b.length()][1]; i <= DP[a.length()][b.length()][2]-2; ++i)
	// 	{
	// 		common += a[i];
	// 	}
 
	// 	for (int j = DP[a.length()][b.length()][3]; j <= DP[a.length()][b.length()][4]-2; ++j)
	// 	{
	// 		common += b[j];				
	// 	}
 
	// 	if (DP[a.length()][b.length()][1] != DP[a.length()][b.length()][2])
	// 	{
	// 		common += a[DP[a.length()][b.length()][2]-1];
	// 	}
 
	// }
	// cout << common << endl;
	answer += common;
 
	for (int i = DP[a.length()][b.length()][4]; i < b.length(); ++i)
	{
		answer += b[i];
	}
	for (int i = DP[a.length()][b.length()][2]; i < a.length(); ++i)
	{
		answer += a[i];
	}
 
	return answer;
}
 
int main(int argc, char const *argv[])
{
	
	// cout << mach.Solve("apple", "pear")<< endl;
	// cout << mach.Solve("apple", "peach")<< endl;
	// cout << mach.Solve("ananas", "banana")<< endl;
	// cout << mach.Solve("pear", "peach")<< endl;
	// cout << mach.Solve("hello", "mask")<< endl;
 
	string x, y;
	while (std::cin >> x)
	{
		cin >> y;
		ADFRUITS mach;
	    cout << mach.Solve(x,y) << endl;
	}
 
	return 0;
}