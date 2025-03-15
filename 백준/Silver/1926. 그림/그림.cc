#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

int MAP[500][500] = {0};
bool visited[500][500] = {false};
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int calculateSize(int row, int col) {
  int size = 0;
  queue<pair<int, int>> q;

  q.push({row, col});
  visited[row][col] = true;
  size += 1;

  while (!q.empty()) {
    auto temp = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int next_row = temp.first + direction[i][0];
      int next_col = temp.second + direction[i][1];

      if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= M) continue;
      if (visited[next_row][next_col] == true || MAP[next_row][next_col] == 0) continue;

      q.push({next_row, next_col});
      visited[next_row][next_col] = true;
      size += 1;
    }
  }

  return size;
}

void Input() {
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> MAP[i][j];
}

void Solve() {
  int result_size = 0;
  int result_cnt = 0;
  Input();

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (MAP[i][j] == 1 && visited[i][j] == false) {
        result_cnt += 1;
        result_size = max(result_size, calculateSize(i, j));
      }
    }
  }

  cout << result_cnt << '\n' << result_size << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}