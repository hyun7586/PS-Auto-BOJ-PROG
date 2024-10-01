#include <bits/stdc++.h>
using namespace std;

int N, K;
int *DP;
vector<int> coins;

void Input()
{
  cin >> N >> K;

  int temp;
  DP = new int[K + 1];

  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    coins.push_back(temp);
  }
}

void Solve()
{
  Input();

  // sort & 중복 제거
  sort(coins.begin(), coins.end());
  coins.erase(unique(coins.begin(), coins.end()), coins.end());

  // caculate DP[]
  DP[0] = 0;
  for (int w = 1; w <= K; w++)
  {
    vector<int> temp_coins;
    for (int i = 0; i < N; i++)
    {
      if (coins[i] <= w && DP[w - coins[i]] != -1)
      {
        temp_coins.push_back(DP[w - coins[i]] + 1);
      }
    }
    // temp_coins.size()==0인 경우?
    if (temp_coins.size() == 0)
    {
      DP[w] = -1;
    }
    else
    {
      DP[w] = *min_element(temp_coins.begin(), temp_coins.end());
    }
  }

  // for (int i = 0; i <= K; i++)
  //   cout << "DP[" << i << "]: " << DP[i] << '\n';
  cout << DP[K];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}