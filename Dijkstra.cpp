/**
	@author : nazmul_islam
*/
#include <bits/stdc++.h>

#define SIZE 10000

using namespace std;

typedef long long ll;

struct node{
	/**u denotes current node no &
    w denotes the minimum cost of exploring current node.*/
	int u, w;

	node(int a, int b){
	    u = a; w = b;
	}

	/**Define priority of node in respect of cost to reach it.*/
	bool operator < ( const node& p ) const {  return w > p.w; }
};

vector<pair<int, int> >g[SIZE];
int cost[SIZE], parent[SIZE];

int dijkstra(int source, int destination)
{
	memset(cost, 63, sizeof cost); //Initialize cost with maximum cost
	memset(parent, -1, sizeof parent); //Initialize parents of all node with -1

	priority_queue<node> q;
	q.push(node(source, 0)); //Visiting source node requires no cost at all.
	cost[source] = 0;

	while(!q.empty())
	{
		int u = q.top().u;
		q.pop();

		if(u == destination)
            return cost[destination];

		for(int i=0; i<g[u].size(); i++)
		{
			int v = g[u][i].first;
			int c = g[u][i].second;

			if(cost[u] + c < cost[v])
			{
				cost[v] = cost[u]+c;
				parent[v] = u;
				q.push(node(v, cost[v]));
			}
		}
	}

	//If we can't reach our destination
	return -1;
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
    //freopen("input.in", "r", stdin);

	int n, e;
	cin>>n>>e;

	for(int i = 0; i<e; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

    int src, dest;
    cin>>src>>dest;

	int ret = dijkstra(src, dest);

	if(ret == -1)
        cout<<"No path!\n";
	else
    {
        cout<<"Cost of reaching "<<src<<" to "<<dest<<" is: "<<ret<<"\n";
        cout<<"Path: ";
        printPath(dest);
    }

	return 0;
}

/**
Test input:
-----------
6 8
1 2 1
1 3 1
2 5 7
2 4 1
3 4 5
4 5 3
4 6 1
5 6 1
1 5
*/