
#include <iostream>
using namespace std;

int main()
{
    int vertices,edges;
    int cases = 0;
    int * ver_arr = new int[cases];
    int * edge_arr = new int[cases];
    while(scanf("%d%d",&vertices,&edges) && vertices != 0 && edges != 0)
    {
        ver_arr[cases] = vertices;
        edge_arr[cases] = edges;

        int head, tail;
        for(int i = 0; i <edges; i++)
        {
            scanf("%d%d",&head,&tail);
        }
        cases ++;
    }
    //print out output
    for(int i = 0; i < cases; i++)
    {
        int result = ver_arr[i] - edge_arr[i];
        if(result == 0)
        {
            cout << "Cases " << (i+1) << ": No trees." <<endl;
        }
        else if (result == 1)
        {
            cout << "Cases " << (i+1) << ": There is one tree." <<endl;
        }
        else
        {
            cout << "Cases " << (i+1) << ": a forest of " << result << " trees." <<endl;
        }
    }
    delete[] ver_arr;
    delete[] edge_arr;
    return 0;
}