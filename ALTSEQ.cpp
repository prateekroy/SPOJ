#include <iostream>
#include <vector>
#include "limits.h"
using namespace std;
 
typedef long long LL;
class ALTSEQ
{
public:
 
	int Solve(vector<LL> array);
};
 
bool isToggle(LL a, LL b){
	if(a < 0 && b >= 0){
		return true;
	}
	else if (a >= 0 && b < 0)
	{
		return true;
	}
	return false;
}
 
LL myabs(LL a){
	if (a < 0)
	{
		return -a;
	}
	return a;
}
 
LL mymax(LL a, LL b){
	if (a > b)
	{
		return a;
	}
	return b;
}
 
int ALTSEQ::Solve(vector<LL> array){
 
	int* DP = new int[array.size()];
	for (int i = 0; i < array.size(); ++i)
	{
		DP[i] = 1;
	}
 
 
	for (int i = 1; i < array.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (myabs(array[i]) > myabs(array[j]) && isToggle(array[i], array[j]))
			{
				DP[i] = mymax(DP[i], DP[j]+1);
			}
		}
	}
 
	// for (int i = 0; i < array.size(); ++i)
	// {
	// 	cout << DP[i] << " ";
	// }
 
	int answer = 1;
	for (int i = 0; i < array.size(); ++i)
	{
		answer = mymax(answer, DP[i]);
	}
	return answer;
}
 
int main(int argc, char const *argv[])
{
 
 
	int N;
	cin >> N;
	LL x;
	std::vector<LL> vecc;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		vecc.push_back(x);
	}
	ALTSEQ mach;
	cout << mach.Solve(vecc) << endl;
	return 0;
}