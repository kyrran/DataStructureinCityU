#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int find(int x,vector<int> &name)
{
    return name[x];

    /* if(name[x]==x) return x;
    return name[x] = find(name[x],name); */
}

bool Union(int x, int y,vector<int> &name)
{
    /* int px = find(x,name);
    int py = find(y,name);
    if(px != py)
    {
        name[py] = px;
        return true;
    }
    //have cycle
    return false; */
    if(find(x,name)!=find(y,name))
    {
        int temp = name[y];
        for(int k=0; k <name.size(); k++)
        {
            if(name[k]==temp)
            {
                name[k] = name[x];
            }
        }
        return true;
    }
    return false;
}

void print(int n, int counter)
{
    // print out output
    
        if (n == 0)
        {
            cout << "Case " << counter << ": No trees." << endl;
        }
        else if (n == 1)
        {
            cout << "Case " << counter << ": There is one tree." << endl;
        }
        else
        {
            cout << "Case " << counter << ": A forest of " << n << " trees." << endl;
        }
    
}

int main()
{
    vector<int> name;
    int n ,m, u, v;
    vector<int> resl;
    //bool visited[505];
    int counter = 0;
    while (cin >> n >> m && n != 0 || m != 0)
    {
        counter++;
        if(m == 0 )
        {
            print(n,counter);
            //resl.push_back(n);
            continue;
        }

        if(n == 0 )
        {
            for (int i = 0; i < m; i++)
            {
                cin >> u >> v;
            }
            print(0,counter);
            //resl.push_back(n);
            continue;
        }

        
        for (int i = 0; i <= n; i++)
        {
            name.push_back(i);
        }
        

        //memset(visited, false, sizeof(visited));
      
        int c = 0;
       
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            //visited[u] = 1;
            //visited[v] = 1;

            if(Union(u,v,name) == false)
            {
                //wheter there is at least a component contains cycle
               
                for(int d = 0; d <= n; d++)
                    if(name[d] == name[u] || name[d] == name[v] )
                        name[d] = 0;
            }
            
        }
        // for(int i = 0; i < name.size(); i++)
        // {
        //     cout << name[i];
        // }
        // cout << endl; 
        sort(name.begin(),name.end());
        //cout << name.size() << endl;
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
            if(*it == 0)
            {
                continue;
            }
            con++;
        }
        print(con,counter);
        //resl.push_back(con);
        
        name.clear();
        
        
    }
    // print out output
    /* int counter = 1;
    for (vector<int>::iterator it = resl.begin(); it != resl.end(); it++)
    {
        if (*it == 0)
        {
            cout << "Case " << counter << ": No trees." << endl;
        }
        else if (*it == 1)
        {
            cout << "Case " << counter << ": There is one tree." << endl;
        }
        else
        {
            cout << "Case " << counter << ": A forest of " << *it << " trees." << endl;
        }
        counter++;
    } */
    
    return 0;
}