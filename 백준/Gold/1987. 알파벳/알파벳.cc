#include <bits/stdc++.h>
using namespace std;

int R, C, max_value = 0;
bool visited[20][20] = {false};
int arr[20][20];
bool used[24] = {false};
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void Input() {
  cin >> R >> C;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      char ch;
      cin >> ch;
      arr[i][j] = (int)ch - 'A';
    }
}

void dfs(int row, int col, int cnt) {
  // cout << "arrive: (" << row << ", " << col << ")\n";
  if (max_value < cnt) max_value = cnt;

  visited[row][col] = true;
  used[arr[row][col]] = true;

  for (int i = 0; i < 4; i++) {
    int ti = row + direction[i][0];
    int tj = col + direction[i][1];

    // cout << "searching: (" << ti << ", " << tj << ")\n";

    if (ti < 0 || ti >= R || tj < 0 || tj >= C) continue;
    if (used[arr[ti][tj]] == true) {
      // cout << "used[]==true : " << arr[ti][tj] << "\n";
      continue;
    }

    if (visited[ti][tj] == true) {
      // cout << "visited==true: (" << ti << ", " << tj << ")\n";
      continue;
    }

    dfs(ti, tj, cnt + 1);

    // cout << "arrive again: (" << row << ", " << col << ")\n";
    used[arr[ti][tj]] = false;
    visited[ti][tj] = false;
  }
}

void Solve() {
  Input();
  dfs(0, 0, 1);

  cout << max_value;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}