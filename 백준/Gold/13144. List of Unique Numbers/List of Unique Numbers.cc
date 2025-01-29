#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100000];
bool visited[100001] = {false};

void Input() {
  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];
}

void Solve() {
  Input();

  int i = 0, j = 0;
  long long cnt = 1;
  visited[arr[0]] = true;

  while (true) {
    // i가 j를 지나쳐 간 경우 visited 체크가 안 되었을 수도 있음.
    if (!visited[arr[i]]) {
      visited[arr[i]] = true;
      cnt += 1;
    }

    // exit conditions
    if (i == N - 1 && j == N - 1) break;

    if (j == N - 1 || visited[arr[j + 1]] == true) {
      i += 1;
      cnt += (j - i + 1);
      visited[arr[i - 1]] = false;
    } else if (visited[arr[j + 1]] == false) {
      j += 1;
      cnt += 1;
      visited[arr[j]] = true;
    }

    if (i > j) j = i;
  }

  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}