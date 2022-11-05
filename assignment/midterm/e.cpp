#include <iostream>
using namespace std;
#include <stack>

int main()
{
    //get the sum array till ith value
    int days;
    scanf("%d",&days);

    int* arr = new int [days + 2];
    // _ 3 1  6  4  5  2 _ <- arr
    // 0 3 4 10 14 19 21 <- sum
    int * sum = new int [days + 1];
    sum[0] = 0;
    arr[0] = -1;
    arr[days] = -1;
    for(int i = 1; i <= days; i++)
    {
        int val;
        scanf("%d",&val);
        arr[i] = val;

        sum[i] = arr[i] + sum[i-1];
        //cout << sum[i] <<endl;
    }
    int rpos,lpos;
    int * joy_sumval = new int [days+1];
    int * lindex = new int [days+1];//_ 1-n
    int * rindex = new int [days+1];
    for(int j = 1; j < days + 1; j++)
    {
        rpos = j + 1;
        while(arr[j] <= arr[rpos] && rpos <= days + 1)
        {
            rpos++;
        }
        rpos -= 1;
        //cout << "rpos: " << rpos << endl;
        rindex[j] = rpos;
        //store the sum value until rpos, pos0 undefined
        joy_sumval[j] = sum[rpos];
        //cout << "r: " << joy_sumval[j] << " ";

        
        lpos = j-1;
        while(arr[j] <= arr[lpos] && lpos >= 0)
        {
            lpos--;
        }
        lpos += 1;
        //cout << "lpos: " << lpos << endl;
        lindex[j] = lpos;
        joy_sumval[j] -= sum[lpos-1];
        joy_sumval[j] *= arr[j];
        //cout << "l: " << joy_sumval[j] << endl;
        //cout << j << endl;
    }
    
    stack<int> stack;
    int max = -1;
    int p_l;
    int p_r;
    for(int i = 1; i < days + 1; i++)
    {
        int v2  = joy_sumval[i];
        if(stack.empty())
        {
            stack.push(v2);
            max = v2;
            p_l = lindex[i];
            p_r = rindex[i];
        }
        else
        {
            int v1 = stack.top();
            if(v2 > v1)
            {
                stack.pop();
                stack.push(v2);
                max = v2;
                p_l = lindex[i];
                p_r = rindex[i];
            }
        }
        //cout << max << endl;
    }
    cout << max << endl;
    cout << p_l << " " << p_r << endl;
    delete[] lindex;
    delete[] rindex;
    delete[] joy_sumval;
    delete [] arr;
    delete [] sum;
    return 0;
}