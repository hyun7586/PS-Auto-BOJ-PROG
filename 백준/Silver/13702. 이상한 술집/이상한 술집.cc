#include <bits/stdc++.h>
using namespace std;

int N, K;
long long arr[100005] = {0};
long long result = 0;

void Input() {
  cin >> N >> K;

  for (int i = 0; i < N; i++) cin >> arr[i];
}

void Solve() {
  Input();

  long long left = 0, right = *max_element(arr, arr + N);
  long long middle;

  while (left <= right) {
    middle = (left + right) / 2;

    int cnt = 0;
    if (middle != 0)
      for (long long each : arr) cnt += each / middle;

    // cout << "left, right, middle, cnt: " << left << " " << right << " " << middle << " " << cnt << '\n';

    if (middle == 0) {
      left = middle + 1;
    } else if (cnt < K) {
      right = middle - 1;
    } else if (cnt >= K) {
      result = middle;
      left = middle + 1;
    }
  }

  cout << result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}