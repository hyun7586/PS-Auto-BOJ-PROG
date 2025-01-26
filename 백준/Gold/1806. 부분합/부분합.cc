#include <bits/stdc++.h>
using namespace std;

int N, S, min_len = INT_MAX, j = 0, s = 0;
int arr[100000];

void Input() {
  cin >> N >> S;

  for (int i = 0; i < N; i++) cin >> arr[i];
}

void Solve() {
  Input();

  for (int i = 0; i < N; i++) {
    if (i != 0) s -= arr[i - 1];

    while (s < S && j < N) {
      s += arr[j++];
    }

    if (s >= S) {
      min_len = min(min_len, j - i);
    }

    if (s < S && j == N) break;
  }

  if (min_len == INT_MAX) min_len = 0;
  cout << min_len;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}