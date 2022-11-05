#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    
    while(scanf("%d",&n) != EOF)
    {
        int *arr = new int[n];
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            arr[i] = val;
            sum += arr[i];
            //cout << "arr[i]: " << arr[i] << endl;
        }
        //goes left or right doesnt affect the cost result
        int pos = sum / n;
        int cost = 0;
        for(int i = 0; i < n; i++)
        {
            cost += abs(arr[i]-pos);
            //cout << "cost: " << cost << endl;
        }
        cout << cost << endl;
        delete [] arr;
    }
    return 0;
}