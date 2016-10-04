/**
    @author: nazmul_islam
*/
#include <bits/stdc++.h>

using namespace std;

#define SIZE 10000

vector<int>g[SIZE];
int cost[SIZE], parent[SIZE];

void DFS(int u)
{
    for(int i = 0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if((cost[u] + 1)<cost[v])
        {
            cost[v] = cost[u] + 1;
            parent[v] = u;
            DFS(v);
        }
    }
}

void printPath(int d)
{
    if(parent[d] == -1)
    {
        cout<<d<<" ";
        return;
    }

    printPath(parent[d]);
    cout<<d<<" ";
}

int main()
{
        int n, e;
	cin>>n>>e;

	for(int i = 0; i<e; i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

    int src, dest;
    cin>>src>>dest;

    memset(cost, 63, sizeof cost); //Initialize cost with maximum cost
	memset(parent, -1, sizeof parent); //Initialize parents of all node with -1
    cost[src] = 0; //Cost of going form source to source is 0
    DFS(src);

	if(cost[dest] == -1)
        cout<<"No path!\n";
	else
    {
        cout<<"Cost of reaching "<<src<<" to "<<dest<<" is: "<<cost[dest]<<"\n";
        cout<<"Path: ";
        printPath(dest);
    }

    return 0;
}

/**
Test input:
-----------
6 8
1 2
1 3
2 5
2 4
3 4
4 5
4 6
5 6
1 5
*/
