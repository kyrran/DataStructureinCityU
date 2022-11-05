//1000 - 9999
#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>

#define MAX 10000
#define MIN 1000
#define DIGIT 4

bool pTable[MAX];
int dis[MAX];

using namespace std;

bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;

        }
    }
    return true;
}

void getTable()
{
    memset(pTable,1,sizeof(pTable));
    for(int i = MIN; i < MAX; i++)
    {
        if(isPrime(i) == false)
        {
            pTable[i] = 0;
        }
    }
}


void BFS (int before, int after)
{   
    memset(dis,0,sizeof(dis));
    if(before == after)
    {
        cout << 0 << endl;
        return;
    }
    queue <int> q;
    q.push(before);

    while(!q.empty())
    {
        int id = q.front();
        q.pop();

        int digit[DIGIT] = {id/1000, (id/100)%10,
                                (id%100)/10, id%10};
        for(int i = 0; i < DIGIT; i++)
        {
            for(int j = 0; j <= 9; j++)
            {
                if(i == 0 && j == 0) j++;
                //this test digit is the current digit
                if(digit[i] == j)
                {
                    continue;
                }

                int cur = digit[i];

                //replace digit by tesst
                digit[i] = j;
                int newID = digit[0]*1000 + digit[1]*100
                            + digit[2]*10 + digit[3]*1;

                if(pTable[newID] && dis[newID]==0)
                {
                    q.push(newID);
                    dis[newID] = dis[id] + 1; 
                }

                if(newID == after)
                {
                    //distance updated
                    return;
                }
                digit[i] = cur;

            }
        }
    }
}

int main()
{
    int n,before,after;
    cin >> n;

    getTable();

    for(int i = 0; i < n; i++)
    {
        cin >> before >> after;
        
        BFS(before,after);
        if(before != after)
        {
            if(dis[after]==0)
            {
                cout << "Impossible" << endl;
            }
            else
            {
                cout << dis[after] << endl;
            }
        }
        
        
    }
    return 0;
}