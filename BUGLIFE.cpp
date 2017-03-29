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
#include <iomanip>
using namespace std;
 
typedef long long LL;
 
// This function returns true if graph G[V][V] is Bipartite, else false
bool isBipartite(map<int, vector<int> > BugGroup, int src, std::vector<int> &visited)
{
    // Create a color array to store colors assigned to all veritces. Vertex 
    // number is used as index in this array. The value '-1' of  colorArr[i] 
    // is used to indicate that no color is assigned to vertex 'i'.  The value 
    // 1 is used to indicate first color is assigned and value 0 indicates 
    // second color is assigned.
    int colorArr[2002];
    for (int i = 0; i < 2002; ++i)
        colorArr[i] = -1;
 
    // Assign first color to source
    colorArr[src] = 1;
 
 
    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);
    visited.push_back(src);
 
    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();
 
         // Find all non-colored adjacent vertices
        for (int vv = 0; vv < BugGroup[u].size(); ++vv)
        {
        	int v = BugGroup[u][vv];
            // An edge from u to v exists and destination v is not colored
            if (colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
                visited.push_back(v);
            }
 
            //  An edge from u to v exists and destination v is colored with
            // same color as u
            else if (colorArr[v] == colorArr[u])
                return false;
        }
    }
 
    // If we reach here, then all adjacent vertices can be colored with 
    // alternate color
    return true;
}
 
 
int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int tc = 0; tc < testcases; ++tc)
	{
		map<int, vector<int> > BugGroup;
		int bugCount, interaction;
		cin >> bugCount >> interaction;
		for (int in = 0; in < interaction; ++in)
		{
			int bugA, bugB;
			cin >> bugA >> bugB;
			BugGroup[bugA].push_back(bugB);
			BugGroup[bugB].push_back(bugA);
 
		}
 
		bool answer = true;
		vector<int> visited;
		for(int bug = 1; bug <= bugCount; bug++){
 
			if(std::find(visited.begin(), visited.end(), bug) == visited.end()){
				// cout << "Try\n";
				if (!isBipartite(BugGroup, bug, visited))
				{
					answer = false;
					break;
				}
			}
		}
 
		cout << "Scenario #" << tc+1 << ":\n";
		answer == true ? cout << "No suspicious bugs found!\n" : cout << "Suspicious bugs found!\n" ;
	}
	return 0;
} 