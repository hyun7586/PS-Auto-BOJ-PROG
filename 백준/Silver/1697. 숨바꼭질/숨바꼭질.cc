#include <bits/stdc++.h>
using namespace std;

#define MAX 200002

int n, m, level = 0;
bool visited[MAX];
int notation[MAX];

void bfs(int start);

int main(void)
{
    cin >> n >> m;

    bfs(n);

    return 0;
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    notation[start] = 0;
    visited[start] = true;

    while (true)
    {
        int y = q.front();
        // find y's level -> temp_level
        int temp_level = notation[y];

        if (y == m)
        {
            cout << notation[y];
            break;
        }

        q.pop();
        visited[y] = true;

        if ((y - 1 >= 0 && y - 1 <= 200000) && !visited[y - 1])
        {
            q.push(y - 1);
            notation[y - 1] = temp_level + 1;
            visited[y - 1] = true;
        }

        if ((y + 1 >= 0 && y + 1 <= 200000) && !visited[y + 1])
        {
            q.push(y + 1);
            notation[y + 1] = temp_level + 1;
            visited[y + 1] = true;
        }

        if ((2 * y >= 0 && 2 * y <= 200000) && !visited[2 * y])
        {
            q.push(2 * y);
            notation[2 * y] = temp_level + 1;
            visited[2 * y] = true;
        }
    }
}