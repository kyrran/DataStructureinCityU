#include <iostream>
#include <list>
using namespace std;

long fac(int n)
{
    int val = 1;
    for(int x = 2; x <= n; x++)
    {
        val *= x;
    }
    return val;
}
long combi(int n, int r)
{
    return fac(n) / (fac(r) * fac(n-r));
}
int main()
{
    int cases,n,val;
    scanf("%d",&cases);
    //int size_arr[10];
    int match_arr[10];

    
    for(int i = 0; i<cases; i++)
    {
        scanf("%d",&n);

        //size_arr[i] = n;
        //cout << "size: " << size_arr[i] << endl;

        int matches = 0;
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&val);
            //1 2 3 4 6 5 8 7
            
            if(val == j+1)
            {
                matches++;
            }
        }
        match_arr[i] = matches;
        //cout << "matches:" << match_arr[i] << endl;
    }


    //output
    for(int i = 0; i < cases; i++)
    {
        //cout << "size2: " << size_arr[i] << endl;
        //cout << "match2: " << match_arr[i] << endl;
        //bionomial calculation
        int result = combi(match_arr[i],2);

        cout << result << endl;
    }

    return 0;
}