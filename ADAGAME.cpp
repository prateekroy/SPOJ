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
#include <iostream>
#include <string> 
#include <sstream>
using namespace std;
// #define CPP11
typedef long long LL;
 
class ADAGAME
{
public:
	int** DP;
	void init();
	bool ifWin(int number, int currentChance, int chances, int originalNumber);
};
 
int reverse(int number){
	
	int ret = 0;
	while(number != 0){
		int a = number % 10;
		ret = ret*10 + a;
		number = number/10;
	}	
	return ret;
}
 
 
 
#ifdef CPP11
vector<int> findFourPoss(int number){
 
	vector<int> answer;
     // ostringstream ss;
     // ss << number;
     // std::string numS = ss.str();
	string numS = std::to_string(number);
 
// cout << numS << endl;
	if (numS.length() < 4)
	{
		while(numS.length() < 4){
			numS = "0" + numS;
		}
	}
 
// cout << numS << endl;
 
 
 
	for (int num = 0; num < 4; ++num)
	{
		string ns = "";
		for (int i = numS.length()-1; i >= 0 ; --i)
		{
			
			if (num == i)
			{
				if (numS[i] == '9')
				{
					ns += '0';
				}
				else
				{
					ns += numS[i] + 1;
				}
			}
			else
			{
				ns += numS[i];
			}
		
		}
		reverse(ns.begin(),ns.end());
		// cout <<  ns << endl;
		// cout << x << endl;
		int x;
		// std::stringstream(ns) >> x;
		x = std::stoi( ns ); 
		answer.push_back(x);	
	}
 
	return answer;
}
 
#else
vector<int> findFourPoss(int number){
 
	vector<int> answer;
     ostringstream ss;
     ss << number;
     std::string numS = ss.str();
 
// cout << numS << endl;
	if (numS.length() < 4)
	{
		while(numS.length() < 4){
			numS = "0" + numS;
		}
	}
 
// cout << numS << endl;
 
 
 
	for (int num = 0; num < 4; ++num)
	{
		string ns = "";
		for (int i = numS.length()-1; i >= 0 ; --i)
		{
			
			if (num == i)
			{
				if (numS[i] == '9')
				{
					ns += '0';
				}
				else
				{
					ns += numS[i] + 1;
				}
			}
			else
			{
				ns += numS[i];
			}
		
		}
		reverse(ns.begin(),ns.end());
		// cout <<  ns << endl;
		// cout << x << endl;
		int x;
		std::stringstream(ns) >> x;
		answer.push_back(x);	
	}
 
	return answer;
}
#endif
 
void ADAGAME::init(){
	
	DP = new int*[10010];
	for (int i = 0; i < 10010; ++i)
	{
		DP[i] = new int[105];
		for (int j = 0; j < 105; ++j)
		{
			DP[i][j] = INT_MAX;
			// DP[i][j] = new int[2];
			// for (int k = 0; k < 2; ++k)
			// {
			// 	DP[i][j][k] = INT_MAX;
			// }
		}
	}
}
 
vector<int> findFourPoss3(int number){
 
	vector<int> answer;
 
	int numberbk = number;
 
		int t = 1;
		while(t < 10000){
 
			int a = numberbk%10;
 
			if (a == 9)
			{
				answer.push_back(number-(t*9));
			}
			else
			{
				answer.push_back(number+t);
			}
 
			numberbk = numberbk/10;
			t = t*10;
		}
 
		return answer;
}
 
bool ADAGAME::ifWin(int number, int currentChance, int chancesLeft, int originalNumber){
 
	//1 -> Ada Wins
	//0 -> Vinit Wins
	// cout << number << " " << currentChance << " " << chancesLeft << endl;
 
	if (DP[number][chancesLeft] != INT_MAX)
	{
		// cout << number << " " << currentChance << " " << chancesLeft << endl;
		return DP[number][chancesLeft];
	}
 
	if (chancesLeft == 0)
	{
		// if (number > originalNumber)
		// {
		// 	return 1;
		// }
		// else
		// {
		// 	return 0;
		// }
		// cout << "return " << (number > originalNumber) << endl;
		if (currentChance == 1 && number > originalNumber)
		{
			// DP[number][chancesLeft][currentChance] = 1;
			return 1;
		}
		else if(currentChance == 1 && number <= originalNumber)
		{
			// DP[number][chancesLeft][currentChance] = 0;
			return 0;
		}
		else if (currentChance == 0 && number > originalNumber)
		{
			// DP[number][chancesLeft][currentChance] = 0;
			return 1;
		}
		else if(currentChance == 0 && number <= originalNumber)
		{
			// DP[number][chancesLeft][currentChance] = 1;
			return 0;
		}
	}
 
	vector<int> possNumbers = findFourPoss3(number);
	for (int i = 0; i < possNumbers.size(); ++i)
	{
		if(currentChance == 1 && ifWin(possNumbers[i], 1-currentChance, chancesLeft-1, originalNumber) != 0){
			// cout << "Why not hit";
			 DP[number][chancesLeft] = 1;
			return 1;
		}
		else if (currentChance == 0 && ifWin(possNumbers[i], 1-currentChance, chancesLeft-1, originalNumber) != 1)
		{
			DP[number][chancesLeft] = 0;
			return 0;
		}
		// DP[possNumbers[i]][chancesLeft-1] = 1-currentChance;
	}
 
	// cout << "return false" << currentChance << " " << chancesLeft << endl;
	 DP[number][chancesLeft] = 1-currentChance;
	return 1-currentChance;
}
 
 
#define CPP11
 
 
 
 
 
int main(int argc, char const *argv[])
{
 
	// for (int i = 0; i < 10000; ++i)
	// {
	// 	cout << i << " -> ";
	// 	vector<int> vc = findFourPoss3(i);
	// 	for (int j = 0; j < vc.size(); ++j)
	// 	{
	// 		cout << vc[j] << " ";
	// 	}
	// 	cout << endl;
	// }
 
 
	// return 0;
 
	int testcases;
	cin >> testcases;
 
	
	for (int tc = 0; tc < testcases; ++tc)
	{
		ADAGAME	mach;
		mach.init();
		int startNumber, chances;
		cin >> startNumber >> chances;
		string answer = (mach.ifWin(startNumber, 1, chances, startNumber) == 0) ? "Vinit\n" : "Ada\n";		
		cout << answer;
	}
 
 
 
	return 0;
} 