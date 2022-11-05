#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


long fac(long n)
{
    long val = 1;
    for(long x = 2; x <= n; x++)
    {
        val *= x;
    }
    return val;
}

long combi(long n, long r)
{
    return fac(n) / (fac(r) * fac(n-r));
}

int main()
{
    int cases;
    long n,item;
    scanf("%d",&cases);
    unordered_map<long, long> map;
    long result[cases];

    for(int i = 0; i<cases; i++)
    {
        scanf("%ld",&n);
        long arr[n];
        for(long j = 0; j < n; j++)
        {
            scanf("%ld",&item);
            arr[j] = item;

            //there is already a same key in map
            if(map.find(arr[j]-j) != map.end())
            {
                //increment the value by 1
                map[arr[j]-j]+= 1;
            }
            else
            {
                //map[key]=value(number of appearance)
                map[arr[j]-j] = 1;
            }
            //cout << map[arr[j]-j] << endl;
        }
        long counter = 0;
        for(unordered_map<long,long>:: iterator it = map.begin(); it != map.end(); it++)
        {
            long frequency = it->second;

            counter += (frequency * (frequency - 1))/2;

        }
        result[i] = counter;
        map.clear();
    }
    
    for(int i = 0; i < cases; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}