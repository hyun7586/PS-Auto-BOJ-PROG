#include <bits/stdc++.h>
using namespace std;

int N, K, mod = 1000000000;
long long DP[201][201] = {
    0,
};

void Input()
{
  cin >> N >> K;
}

void func()
{
  for (int i = 0; i <= K; i++)
    DP[0][i] = 1;

  for (int k = 1; k <= K; k++)
  {
    for (int n = 1; n <= N; n++)
    {
      // DP[n][k] = sum of DP[0~n][k-1]
      for (int i = 0; i <= n; i++)
      {
        DP[n][k] = (DP[n][k] % mod + DP[i][k - 1] % mod) % mod;
      }
    }
  }
}

void Solve()
{
  Input();
  func();

  cout << DP[N][K];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}