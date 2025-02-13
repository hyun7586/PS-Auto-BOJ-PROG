#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    long long cnt = 0;
    scanf("%d", &n);

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    sort(arr, arr + n);

    int left = 0, right = n - 1;
    while (left < right)
    {
        long long temp = arr[left] + arr[right];
        if (temp < x)
            left += 1;
        else if (temp == x)
        {
            cnt += 1;
            left += 1;
            // right -= 1;
        }
        else if (temp > x)
            right -= 1;
    }

    printf("%d", cnt);

    return 0;
}