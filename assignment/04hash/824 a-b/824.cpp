#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

/* template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
 */
int main()
{
    long n,c,item;
    unordered_map<long, long> map;
    queue<long> q;

    
    while (scanf("%ld%ld", &n,&c) != EOF) {
        long arr[n];
        //put every element in array into map and count their duplicates
        for(long i = 0; i < n; i++)
        {
            ///int duplicate = 1;
            scanf("%ld",&item);
            arr[i] = item;

            //there is already a same key in map
            if(map.find(arr[i]) != map.end())
            {
                //increment the value by 1
                map[arr[i]]+= 1;
            }
            else
            {
                //map[key]=value(number of appearance)
                map[arr[i]] = 1;
            }
            
        }
        //print_map(map);
        long counter = 0;
        //find pairs
        for(long i = 0; i < n; i++)
        {
            //aj = ai - c
            //ai is key value of map
            //also the element value of array
            long ai = arr[i];
            //cout << "ai-c: " << ai-c << endl;
            //if same key exists in map
            if(map.find(ai - c) != map.end())
            {
                //read their duplicate values by key
                counter += map[ai - c];
                //cout << counter <<endl;
            }
            
        }
        q.push(counter);
        //cout << counter << endl;
        map.clear();
    }

    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}