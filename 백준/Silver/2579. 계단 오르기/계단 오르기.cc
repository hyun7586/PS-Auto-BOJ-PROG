#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[302] = {
    0,
};
int dp[302] = {
    0,
};

void Input() {
  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];
}

void Solve() {
  Input();

  dp[0] = arr[0];
  dp[1] = arr[0] + arr[1];
  dp[2] = max(arr[0], arr[1]) + arr[2];

  for (int i = 3; i < N; i++) {
    dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
  }

  cout << dp[N - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}