#include <iostream>
#include <math.h> 
#include <string.h>
#define TOTAL_SLOTS 100005
using namespace std;

class MaxHeap
{
    public:
        int size;
        int items[TOTAL_SLOTS];
    
        void insert(int key);
        void pop();
        void printH();
    MaxHeap()
    {
        size = 0;
        memset(items,-1,sizeof(items));
    }
};

void MaxHeap::insert(int key)
{
    int temp;
    int i = size;
    items[i] = key;
    size++;
    while(items[i]>items[(i-1)/2] && i!=0)
    {
        swap(items[i],items[(i-1)/2]);
        i = (i-1)/2;
    }
    
}

void MaxHeap::pop()
{
    int temp, value;
    int i=size;
    value=items[0];
    items[0]=items[i-1];
    size--;
    int hole=0;
    int child = 2*hole+1;
    temp=items[hole];
    for(; hole*2+1 < size; hole=child)
    {
        child = hole*2+1;
        if(items[child+1] > items[child])
        {
            child++;
        }
        if(items[child] > temp)
        {
            items[hole] = items[child];
        }
        else
            break;
    }

    items[hole] = temp;
    

}

void MaxHeap::printH()
{
    for(int j = 0; j < size; j++)
    {
        cout << items[j] << " ";
    }
    cout <<endl;
}

int main()
{
    int nOp;
    while(scanf("%d",&nOp)!= EOF)
    {
        MaxHeap * h = new MaxHeap();
    int res = 0;

    for(int i = 0; i < nOp;i++)
    {
        int num;
        char ch;
        cin >> ch;
        if(ch == 'a')
        {
            cin >> num;
            h->insert(num);
            //h->printH();
            
        }
        else if(ch == 'p' )
        {
            
            h->pop();
            //h->printH();
        }
        else if(ch == 'r')
        {
            res = 0;
            //h->printH();
           
            for(int j = 0; j < h->size; j++)
            {
                res += h->items[j];
            }
            cout << res << endl;
        }

    }
    }
    
    
    
    

    
}