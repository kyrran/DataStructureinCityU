#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
bool visited[505];

int find(int x,vector<int> &name)
{
    if(name[x]==x) return x;
    return name[x] = find(name[x],name);
}

bool Union(int x, int y,vector<int> &name)
{
    int px = find(x,name);
    int py = find(y,name);
    if(px != py)
    {
        name[py] = px;
        return true;
    }

    //have cycle
    return false;
}

int main()
{
    vector<int> name;
    int n, m, u, v;
    vector<int> resl;
    while (cin >> n >> m && n != 0 || m != 0)
    {
        if(m == 0)
        {
            resl.push_back(n);
            continue;
        }

        name.clear();
        for (int i = 0; i <= n; i++)
        {
            name.push_back(i);
        }
        memset(visited, false, sizeof(visited));
      
        int c = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            visited[u] = 1;
            //visited[v] = 1;

            if(Union(u,v,name) == 0)
            {
                //wheter there is at least a component contains cycle
               
                for(int d = 0; d <= n; d++)
                    if(name[d] == name[u] || name[d] == name[v] )
                        name[d] = -1;
            }
            
        }
        vector<int>::iterator it;
        for (int i = 1; i <= n; i++)
        {
            
            it = unique(name.begin(), name.end());
            name.resize(distance(name.begin(),it));
            int diff;
            int com = name[i];
        }
        int con = 0;
        for(it = name.begin(); it!= name.end(); ++it)
        {
            if(*it == 0 || *it == -1)
            {
                continue;
            }
            con++;
        }
        resl.push_back(con);

    }
    // print out output
    int counter = 1;
    for (vector<int>::iterator it = resl.begin(); it != resl.end(); it++)
    {
        if (*it == 0)
        {
            cout << "Cases " << counter << ": No trees." << endl;
        }
        else if (*it == 1)
        {
            cout << "Cases " << counter << ": There is one tree." << endl;
        }
        else
        {
            cout << "Cases " << counter << ": A forest of " << *it << " trees." << endl;
        }
        counter++;
    }
    
    return 0;
}