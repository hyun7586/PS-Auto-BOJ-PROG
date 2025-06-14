#include <bits/stdc++.h>
using namespace std;

int n, minest = 987654321;
int **arr;
int **cost;

int main()
{
    cin >> n;

    arr = new int *[n];
    cost = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[3];
        cost[i] = new int[3];
    }
    for (int i = 0; i < n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    arr[0][0] = cost[0][0];
    arr[0][1] = cost[0][1];
    arr[0][2] = cost[0][2];

    for (int i = 1; i < n; i++)
    {
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[i][0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[i][1];
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[i][2];
    }

    cout << min(arr[n - 1][0], min(arr[n - 1][1], arr[n - 1][2]));

    return 0;
}