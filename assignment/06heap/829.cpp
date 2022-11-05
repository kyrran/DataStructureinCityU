#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#define TOTAL_SLOTS 100005
using namespace std;

class MaxHeap
{
public:
    long int size;
    long int items[TOTAL_SLOTS];

    void insert(long int key);
    long int pop();
    void printH();
    MaxHeap()
    {
        size = 0;
        memset(items, -1, sizeof(items));
    }
};
class MinHeap
{
public:
    long int sizeM;
    long int itemsM[TOTAL_SLOTS];

    void insertM(long int key);
    long int popM();
    void printM();
    MinHeap()
    {
        sizeM = 0;
        memset(itemsM, -1, sizeof(itemsM));
    }
};

void MaxHeap::insert(long int key)
{
    long int temp;
    long int i = size;
    items[i] = key;
    size++;
    while (items[i] > items[(i - 1) / 2] && i != 0)
    {
        swap(items[i], items[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

long int MaxHeap::pop()
{
    long int temp, value;
    long int i = size;
    value = items[0];
    items[0] = items[i - 1];
    size--;
    long int hole = 0;
    long int child = 2 * hole + 1;
    temp = items[hole];
    for (; hole * 2 + 1 < size; hole = child)
    {
        child = hole * 2 + 1;
        if (items[child + 1] > items[child])
        {
            child++;
        }
        if (items[child] > temp)
        {
            items[hole] = items[child];
        }
        else
            break;
    }

    items[hole] = temp;
    return value;
}

void MaxHeap::printH()
{
    for (long int j = 0; j < size; j++)
    {
        cout << items[j] << " ";
    }
    cout << endl;
}

void MinHeap::insertM(long int key)
{
    long int temp;
    long int i = sizeM;
    itemsM[i] = key;
    sizeM++;
    while (itemsM[i] < itemsM[(i - 1) / 2] && i != 0)
    {
        swap(itemsM[i], itemsM[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

long int MinHeap::popM()
{
    long int temp, value;
    long int i = sizeM;
    value = itemsM[0];
    itemsM[0] = itemsM[i - 1];
    sizeM--;
    long int hole = 0;
    long int child = 2 * hole + 1;
    temp = itemsM[hole];
    for (; hole * 2 + 1 < sizeM; hole = child)
    {
        child = hole * 2 + 1;
        if (itemsM[child + 1] < itemsM[child])
        {
            child++;
        }
        if (itemsM[child] < temp)
        {
            itemsM[hole] = itemsM[child];
        }
        else
            break;
    }

    itemsM[hole] = temp;
    return value;
}

void MinHeap::printM()
{
    for (long int j = 0; j < sizeM; j++)
    {
        cout << itemsM[j] << " ";
    }
    cout << endl;
}

void wheretoAdd(long int x, MaxHeap *max, MinHeap *min)
{

    if (max->size == 0)
    {
        max->insert(x);
    }
    else
    {
        if (max->size == min->sizeM)
        {
            if (x < max->items[0])
            {
                max->insert(x);
            }
            else
            {
                min->insertM(x);
            }
        }
        else if (max->size < min->sizeM)
        {
            if (x < max->items[0])
            {
                max->insert(x);
            }
            else
            {
                long int z = min->popM();
                max->insert(z);
                min->insertM(x);
            }
        }
        else if (max->size > min->sizeM)
        {
            if (x > max->items[0])
            {
                min->insertM(x);
            }
            else
            {
                long int z = max->pop();
                min->insertM(z);
                max->insert(x);
            }
        }
    }
}

long int getM(MaxHeap *max, MinHeap *min)
{
    if (max->size == min->sizeM)
    {
        return (max->items[0] + min->itemsM[0]) / 2.0;
    }
    else if (max->size < min->sizeM)
    {
        return min->itemsM[0];
    }
    else
    {
        return max->items[0];
    }
}
void addNum(int num,MaxHeap *max, MinHeap *min )
{

    if (max->size == min->sizeM)
    {
        min->insertM(num);
        int top = min->itemsM[0];
        min->popM();
        max->insert(top);
    }
    else
    {
        max->insert(num);
        int top = max->items[0];
        max->pop();
        min->insertM(top);
    }
}
long int findMedian(MaxHeap *max, MinHeap *min) 
{
        if (max->size== min->sizeM) {
            return (max->items[0]+min->itemsM[0])*1.0/2;
        } else {
            return max->items[0]*1.0;
        }
}
int main()
{
    long int n = 0;
    cin >> n;
    // 0-10^9
    long int element = 0;
    long int arr[n + 1];
    long int res[n + 1];

    MaxHeap *max = new MaxHeap();
    MinHeap *min = new MinHeap();
    vector<long int> v;
    // n = 7
    //  k = 4

    //  n = 8
    // k = 4.5->4

    // 4, 2.5
    long int k = (n + 1) / 2;

    long int indexL = 0;
    for (long int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        addNum(arr[i], max, min);
        res[i] = findMedian(max, min);
        /* max->printH();
        min->printM();
        cout << "......" << endl; */
    }

    long int p = 1;
    for (long int j = 1; j <= k; j++)
    //[1,2*1-1], 2*2-1, 2*3-1...2*k-1
    // 11 13 15 17
    {
        // 1 3 5 7
        long int indexL = 2 * j - 1;
        cout << res[indexL] << endl;
        /* while(p <= indexL)
        {
            element = arr[p];
            wheretoAdd(element, max, min);

            p++;
        }
        v.push_back(getM(max, min));
        //cout << getM(max, min) << endl; */
    }

    /*  for(vector<long int>::iterator it = v.begin(); it != v.end(); ++it)
     {
         cout << *it << endl;
     } */
}