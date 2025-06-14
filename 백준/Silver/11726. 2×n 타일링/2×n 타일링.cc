#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int MOD = 10007;
long long dp[1001] = {
    0,
};

void Solve() {
  cin >> N;

  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= N; i++) {
    dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
  }

  cout << dp[N];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}