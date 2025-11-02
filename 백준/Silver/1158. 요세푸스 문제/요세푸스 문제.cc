#include <bits/stdc++.h>
using namespace std;

int n, k;
int front = 0, rear = 0;

queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        q.push(i);

    cout << "<";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            int x = q.front();
            q.push(x);
            q.pop();
        }

        int y = q.front();
        q.pop();

        if (i < n - 1)
            cout << y << ", ";
        else if (i == n - 1)
            cout << y << ">";
    }

    return 0;
}
