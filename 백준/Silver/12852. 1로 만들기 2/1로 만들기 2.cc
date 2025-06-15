#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[1000001] = {
    0,
};
int previous_index[1000001] = {
    0,
};

void Solve() {
  cin >> N;

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;

  previous_index[1] = -1;
  previous_index[2] = 1;
  previous_index[3] = 1;

  for (int i = 4; i <= N; i++) {
    int min_value = dp[i - 1], min_index = i - 1;

    if (i % 2 == 0 && min_value > dp[i / 2]) {
      min_value = dp[i / 2];
      min_index = i / 2;
    }

    if (i % 3 == 0 && min_value > dp[i / 3]) {
      min_value = dp[i / 3];
      min_index = i / 3;
    }

    dp[i] = min_value + 1;
    previous_index[i] = min_index;
  }

  cout << dp[N] << '\n';
  for (int i = N; i != -1; i = previous_index[i]) cout << i << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}