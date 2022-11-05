#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
long long int arr[3005][3005];
long long int new_matrix[3005][3005];

int main()
{

    long long int n = 0;
    cin >> n;

    memset(new_matrix, 0, sizeof(new_matrix));

    char ch;
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            cin >> ch;
            if (ch == '0')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }

    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = n - 1; j >= 0; j--)
        {

            if (arr[i][j] == 1 && j != n - 1)
            {
                new_matrix[i][j] += new_matrix[i][j + 1];
            }

            if (arr[i][j] == 0)
            {
                continue;
            }

            new_matrix[i][j] += arr[i][j];
        }
    }

    long long int resl = 0;

    for (long long int col = 0; col < n; col++)
    {
        array<
        stack<pair<long long int, long long int> > s;
        // number of submatrices with all 1s starting from the element
        long long int to_sum = 0;

        for (long long int row = n - 1; row >= 0; row--)
        {
            // the number of elements greater than
            // the current element that was pushed in this stack previously
            long long int Cij = 0;
            // top element is greater than the number to be pusheh
            long long int element = new_matrix[row][col];

            while (s.size() != 0 and s.top().first > element)
            {
                // topmost element of the stack
                long long int Qt = s.top().first;
                // he number of elements previously pushed in the stack
                // with a value greater than the top-most element of the stack
                long long int Ct = s.top().second;

                to_sum -= (Ct + 1) * (Qt - element);

                Cij += Ct + 1;
                s.pop();
            }

            to_sum += element;

            resl += to_sum;

            s.push(make_pair(element, Cij));
        }
    }

    cout << resl << endl;
}