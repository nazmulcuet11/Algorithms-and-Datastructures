/**
    @author : nazmul_islam
*/
#include <bits/stdc++.h>

using namespace std;

int N,E;
vector<int>g[100];
bool visited[100];
stack<int>stk;

void DFS(int u)
{
    visited[u] = true;
    for(int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if(!visited[v])
            DFS(v);
    }
    stk.push(u);
}

void topologicalSort(int noOfVertices)
{
    memset(visited,false,sizeof visited);
    stk.empty();

    for(int i = 1;i<=noOfVertices; i++)
        if(!visited[i])
            DFS(i);
    /**Print stack to find out topological order*/
    while(!stk.empty())
    {
        cout<<stk.top()<<"-->";
        stk.pop();
    }
}

int main()
{
    int i,j;
    cout<<"Enter number of nodes and number of edges:"<<endl;
    scanf("%d%d",&N,&E);
    int indegree[N+1];

    for(i=0; i<=N; i++)
        indegree[i] = 0;

    cout<<"Enter adjacency list:"<<endl;
    for(i=1; i<=E; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        indegree[y]++;
        g[x].push_back(y);
    }

    cout <<"\nNode    Indegree    Outdegree"<<endl;
    for(i=1; i<=N; i++)
    {
        cout<<i<<"        "<<indegree[i]<<"           "<<g[i].size()<<endl;
    }
    cout<<"\n\nToplogical sorted order: ";
    topologicalSort(N);
    cout<<"\n\n";
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
*/

