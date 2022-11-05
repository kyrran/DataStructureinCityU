#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Graph
{   public:

        long long int nVs;
        vector< pair<long long int,long long int> > adjList[];

        void addEdge(long long int u, long long int v, long long int w);

        Graph(long long int v)
        {
            nVs = v;
            adjList[v+1];
        }
};

void Graph::addEdge(long long int u, long long int v, long long int w)
{
    adjList[u].push_back(make_pair(v,w));
    adjList[v].push_back(make_pair(u,w));
}

pair<int, int> BFS (long long int begin, long long int vertices)
{
    long long int distance[vertices];
    memset(distance, -1, sizeof(distance));
 
    queue<int> q;
    q.push(begin);
 
    distance[begin] = 0;
 
    while (!q.empty())
    {
        int t = q.front();       q.pop();
 
        //  loop for all adjacent nodes of node-t
        for (auto it = adj[t].begin(); it != adj[t].end(); it++)
        {
            int v = *it;
 
            // push node into queue only if
            // it is not visited already
            if (dis[v] == -1)
            {
                q.push(v);
 
                // make distance of v, one more
                // than distance of t
                dis[v] = dis[t] + 1;
            }
        }
    }
    
int main()
{
    long long int nCitys,u,v,w;
    scanf("%lld",&nCitys);
    Graph* graph = new Graph(nCitys);

    //index from 1, because we need u and v from 1
    for(long long int i = 0; i < nCitys - 1; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        graph->addEdge(u,v,w);
    }

    
}
