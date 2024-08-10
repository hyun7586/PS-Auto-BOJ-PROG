/*
 avoided by too high time complexity
 use modified_visited array : default set by -1, if it arrive first time -> set
 by 0

 consider iteration(bottom-up approach) instead of recursion
 */

#include <bits/stdc++.h>
using namespace std;

int R, C, result = 0;
int score_map[500][500];
int DP[500][500];

int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(int r, int c) {
  if (r == R - 1 && c == C - 1)
    return 1;
  else
    DP[r][c] = 0;

  for (int i = 0; i < 4; i++) {
    int next_r = r + direction[i][0];
    int next_c = c + direction[i][1];

    if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;

    if (score_map[r][c] > score_map[next_r][next_c]) {
      if (DP[next_r][next_c] == -1)
        DP[r][c] += dfs(next_r, next_c);

      else if (DP[next_r][next_c] > 0)
        DP[r][c] += DP[next_r][next_c];
    }
  }

  return DP[r][c];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      DP[i][j] = -1;
      cin >> score_map[i][j];
    }

  dfs(0, 0);

  cout << DP[0][0];

  return 0;
}