#include <bits/stdc++.h>
using namespace std;

int N, result = 0;
int DP[500][500] = {0};
int _map[500][500];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void Input() {
  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> _map[i][j];
}

int dfs_func(int row, int col) {
  // 현재 row, col에서 이동 가능한 최대 칸수를 return하는 함수
  // search for 4 directions
  for (int i = 0; i < 4; i++) {
    int next_row = row + direction[i][0];
    int next_col = col + direction[i][1];

    // bound check
    if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N) continue;

    // next 칸의 대나무값이 현재칸보다 더 커야 이동 가능
    if (_map[row][col] >= _map[next_row][next_col]) continue;

    // 이미 방문한 칸이라면
    if (DP[next_row][next_col] != 0) {
      // 다음으로 방문할 칸의 DP+1이 현재 칸의 DP보다 커야지 DP값 update
      if (DP[row][col] < DP[next_row][next_col] + 1) {
        DP[row][col] = DP[next_row][next_col] + 1;
      }
      continue;

    }
    // 방문하지 않은 칸이라면: 대나무값 체크 후 이동
    else {
      int temp = dfs_func(next_row, next_col) + 1;
      if (temp > DP[row][col]) DP[row][col] = temp;
    }
  }

  // exit conditions
  // 4방향을 모두 탐색하고 난 뒤.
  return DP[row][col];
}

void Solve() {
  Input();

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dfs_func(i, j);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (result < DP[i][j]) result = DP[i][j];

  // 판다를 처음 풀어놓는 것도 이동으로 count함
  cout << result + 1;

  // cout << "DP[][] map:\n";
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << DP[i][j] << " ";
  //   }
  //   cout << '\n';
  // }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}