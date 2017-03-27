#include <iostream>
#include <vector>
#include "limits.h"
#include "math.h"
#include <stdio.h>
#include <float.h>
#include <time.h>
 
using namespace std;
 
struct node{
	int x;
	int y;
};
 
class AMBLE
{
public:
 
	double Solve(std::vector<node> path);
};
 
double mysquare(double val){
	return val*val;
}
 
double myroot(double val){
	return sqrt(val);
}
 
double sqdist(int a, int b, std::vector<node> path){
 
	double answer;
	answer = myroot(mysquare(path[b].y - path[a].y) + mysquare(path[b].x - path[a].x));
 
	return answer;
}
 
double mymin(double a, double b){
	if (a < b)
	{
		return a;
	}
	return b;
}
 
double AMBLE::Solve(std::vector<node> path){
 
	double** DP = new double*[path.size()];
	for (int i = 0; i < path.size(); ++i)
	{
		DP[i] = new double[path.size()];
	}
 
 
	for (int i = 0; i < path.size(); ++i)
	{
		for (int j = 0; j < path.size(); ++j)
		{
			if (j != i)
			{
				DP[i][j] = DBL_MAX;
			}
			else
			{
				DP[i][j] = DBL_MIN;
			}
		}
	}
	DP[0][0] = DBL_MAX;
	DP[path.size()-1][path.size()-1] = 0;
	DP[path.size()-2][path.size()-1] = sqdist(path.size()-2, path.size()-1, path);
 
	for (int i = path.size()-1; i >= 0; --i)
	{
		for (int j = path.size()-1; j >= 0; --j)
		{
			if (DP[i][j] == DBL_MAX)
			{
				if ((j > i) && (i == j-1) || (i == 0 && j == 0))
				{
					int lp = (i == 0 && j == 0) ? 1 : 2;
					// for (int x = i+lp; x < path.size(); ++x)
					// {
					// int x = i+1;
 
					// cout << i << " " << j << endl;
					for (int x = i+1; x < path.size(); ++x)
					{
						if (DP[x][j] != DBL_MIN)
						{
							DP[i][j] = mymin(DP[i][j], DP[x][j] + sqdist(x, i, path));
						}						
					}
 
 
					// 	for (int y = 0; y < path.size(); ++y)
					// 	{
					// 		if (DP[x][y] != DBL_MIN)
					// 		{
					// 			double dist = 0;
					// 			int k = x-1;
 
					// 			dist = DP[x][y] + sqdist(i, x, path) + sqdist(y, k, path);
					// 			for (; k > j; --k)
					// 			{
					// 				dist += sqdist(k, k-1, path);
					// 			}
 
					// 			if (i == 0 && j == 1)
					// 			{
					// 				cout << dist << " " << x << " " << y << endl;
					// 			}
					// 			DP[i][j] = mymin(dist, DP[i][j]);
					// 		}
					// 	}
					// }
				}
				else if(j > i)
				{
					if (DP[i+1][j] != DBL_MAX)
					{
						DP[i][j] = DP[i+1][j] + sqdist(i, i+1, path);
					}
				}
				else if (i > j && i-1 == j)
				{
					for (int k = j+1; k < path.size(); ++k)
					{
						if (DP[i][k] != DBL_MIN)
						{
							DP[i][j] = mymin(DP[i][j] , DP[i][k] + sqdist(j, k, path));
						}	
					}
				}
				else if (i > j)
				{
					if (DP[i][j+1] != DBL_MIN)
					{
						DP[i][j] = DP[i][j+1] + sqdist(j, j+1, path);
					}
					else
					{
						DP[i][j] = DP[i][j+2] + sqdist(j, j+2, path);
					}
				}
			}
		}
	}
 
	// for (int i = 0; i < path.size(); ++i)
	// {
	// 	for (int j = 0; j < path.size(); ++j)
	// 	{
	// 		cout << DP[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
 
	return DP[0][0];
}
 
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
 
 
int main(int argc, char const *argv[])
{
	// clock_t tStart = clock();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	
	AMBLE mach;
	int N;
	cin >> N;
	// scanf("%d", &N);
	// fastscan(N);
	vector<node> vecc;
	for (int i = 0; i < N; ++i)
	{
		int X,Y;
		cin >> X >> Y;
		// scanf("%d", &X);
		// scanf("%d", &Y);
		// fastscan(X);
		// fastscan(Y);
		node n;
		n.x = X;
		n.y = Y;
		vecc.push_back(n);
	}
	printf("%.2f", mach.Solve(vecc));
	// printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
 
 
	return 0;
} 