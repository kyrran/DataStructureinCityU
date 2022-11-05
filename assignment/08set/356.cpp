
/*
4 5
1 2 100
1 3 100
1 4 1
2 3 100
3 4 1

9 14
1 2 9
6 9 8
2 4 9
2 3 9
4 5 1
4 3 9
5 9 2
9 8 9
7 8 9
7 9 5
6 7 9
5 6 4
5 8 7
7 5 9

0 0
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#define MIN -2147483648;
using namespace std;

int BFS(int n, vector<int> citys[])
{
    int ans = 0;
    bool checked[n];

    memset(checked, false, sizeof(checked));
   
    for (int i = 0; i < n; i++)
    {
        if (checked[i] == false)
        {
            int counter = 0;

            queue<int> q;
            q.push(i);
            
            while (!q.empty())
            {
                int whereWeAt = q.front();
                q.pop();

                if (checked[whereWeAt] == false)
                {
                    checked[whereWeAt] = true;

                    counter++;

                    for (vector<int>::iterator j = citys[whereWeAt].begin(); j != citys[whereWeAt].end(); ++j)
                    {
                        int v = *j;
                        if (!checked[v])
                        {
                            q.push(v);
                        }
                    }
                }
            }
            ans = max(ans, counter);
        }
    }
    return ans;
}

int main()
{

    int n, m, depart, desti;
    long weight;

    while (cin >> n >> m && n != 0 && m != 0)
    {
        long ppaM = MIN;
        vector<int> citys[n];

        for (int i = 0; i < m; i++)
        {

            cin >> depart >> desti >> weight;
            ppaM = max(ppaM, weight);

            if (weight == ppaM)
            {
                citys[depart - 1].push_back(desti - 1);
                citys[desti - 1].push_back(depart - 1);
            }
        }

        printf("%d\n", BFS(n, citys));
    }
}
