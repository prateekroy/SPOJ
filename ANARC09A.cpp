#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;
 
class ANARC09A
{
public:
 
	int Solve(string str);
	
};
 
 
int ANARC09A::Solve(string str){
 
	int count = 0;
	int answer = 0;
	for (int i = 0; i < str.length(); i++)
	{
		// if (str[i] == str[i+1])
		// {
		// 	count++;
		// }
		// else if (str[i] != str[i+1] && str[i] == '}' && str[i+1] == '{')
		// {
		// 	count+=2;
		// }
 
 
		if (str[i] == '{')
		{
			answer++;
			continue;
		}
		else if (str[i] == '}')
		{
			if (answer > 0)
			{
				answer--;
			}
			else
			{
				count--;
			}
			continue;
		}
	}
 
 
	return (abs(count)+1)/2 + (answer+1)/2;
}
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
 
// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}
 
// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}
 
// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
 
 
int main(int argc, char const *argv[])
{
	bool br = true;
	string a;
	cin >> a;
	int tc = 0;
 
	trim(a);
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] == '-')
		{
			br = false;
		}
	}
 
	while(br){
 
		ANARC09A mach;
		cout << ++tc << ". " << mach.Solve(a) << endl;
		cin >> a;
		trim(a);
		for (int i = 0; i < a.length(); ++i)
		{
			if (a[i] == '-')
			{
				br = false;
			}
		}
	}
 
	return 0;
} 