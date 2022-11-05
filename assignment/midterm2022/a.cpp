#include <iostream>
#include <list>
using namespace std;
int main()
{
    int cases,n,val;
    scanf("%d",&cases);

    int arr [5][100000];

    for(int i = 0; i<cases; i++)
    {
        scanf("%d",&n);
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&val);
            
            arr[i][j] = val;
            
            //cout << arr[cases][j] << " ";
        }
    }


    //output
    for(int i = 0; i<cases; i++)
    {
        for(int j = n-1; j >=0 ; j--)
        {
            if(arr[i][j] != 0)
            {
                cout << arr[i][j] << " ";
            }
            else
            {
                cout<< "";
            }
           
           
        }
        cout << endl;
    }

    return 0;
}