#include <iostream>
#include <array>
#include <vector>
#define MAXN 50005

using namespace std;
class DisjointSet
{
    public:
        int Find(int x);
        void Union(int x, int y);
   
        int name[MAXN];
};

int DisjointSet::Find(int i)
{
    return name[i];
}

void DisjointSet::Union(int i, int j)
{
    if(Find(i)!=Find(j))
    {
        int temp = name[j];
        for(int k=0; k <MAXN; k++)
        {
            if(name[k]==temp)
            {
                name[k] = name[i];
            }
        }
    }
}
int main()
{
    int n,m;
    int a,b;
    DisjointSet* set = new DisjointSet();
    vector<int> v;
    int ans = 0;
    int counter = 0;
    while(cin >> n >> m && n != 0 || m != 0)
    {
        ans = 0;

        if(m == 0)
        {
            v.push_back(n);
            continue;
        }   
        
        for(int i = 1; i <=n;i++)
        {
            set->name[i] = i;
        }
        for(int i = 1; i <=m;i++)
        {
            cin >> a >> b;
            set->Union(a,b);
        }

        for(int i = 1; i <= n; i++)
        {
        
            if(set->name[i] == i)
            {
                ans++;
            }
        }

        
        v.push_back(ans);
    }

    

    counter = 1;
    for(vector<int>::iterator it = v.begin(); it!= v.end(); it++)
    {
        cout << "Case " << counter <<": " <<*it << endl;
        counter++;
    }

    return 0;
    

    
}