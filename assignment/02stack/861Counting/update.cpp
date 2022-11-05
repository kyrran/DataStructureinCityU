#include <cmath>
#include <string.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <cmath>

using namespace std;
#define MAX 3005

bool arr[MAX][MAX];
int new_matrix[MAX][MAX];

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
            {
                arr[i][j] = 1;
            }
            else if (ch == '1')
            {
                arr[i][j] = 0;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i && j && arr[i][j])
            {
                arr[i][j] += min(min(arr[i - 1][j - 1], arr[i - 1][j]), arr[i][j - 1]);
            }
            ans += arr[i][j];
        }
    }

    cout << ans << endl;
}
