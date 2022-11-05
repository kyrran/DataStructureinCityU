#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


void longestPath2(vector< pair<int,int> > g[],vector <bool> &visitStatus, int u, int &maxSum,int prev)
{
    // city 1
    int nChilds = g[u].size();
    visitStatus[u] = true;
    int weightedSum;
    int i = 0;
    
    //iterate all child nodes of city1
    while(i < nChilds)
    {
        pair < int, int > v_w = g[u][i];
        int v = v_w.first;
        int w = v_w.second;
        // u havent visited v = 1 -> 2
        if(visitStatus[v] == false)
        {
            //weighted sum = previous length + current length
            weightedSum = prev + w;
            //if city2 has chilnode as well?
            //yes-add
            //no -return main to loop next city
            longestPath2(g, visitStatus, v, maxSum, weightedSum);
        
        }
            
        //the weightsum of one of 1's childnodes
        //larger than currect max? update
        if (maxSum < weightedSum)
        {
            maxSum = weightedSum;
        }
        //to tranverse other chilnode of city1
        weightedSum = 0;
        i++;
    }

    //the final weight will be the longest path of current city, city 1
}

int main()
{
    int nCitys,u,v,w;
    scanf("%d",&nCitys);
 
    //index from 1, because we need u and v from 1
    vector< pair<int,int> > graph[nCitys+1];
    pair <int,int> pair1,pair2;
    for(int i = 0; i < nCitys - 1; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        pair1 = make_pair(v, w);
        pair2 = make_pair(u, w);
        //graph[city 1], pair vector (destination, weighte of edge)
        graph[u].push_back(pair1);
        graph[v].push_back(pair2);
    }

    vector <bool> visitStatus(nCitys + 1);
    int maxSum = 0;
    for(int i = 1; i <= nCitys; i++)
    {
        fill(visitStatus.begin(),visitStatus.end(),false);
        // g[], u, maxSum, weightedSum, &visitStatu
        longestPath2(graph,visitStatus, i, maxSum ,0);

    }
    
    cout << maxSum << endl;
    return 0;
}
