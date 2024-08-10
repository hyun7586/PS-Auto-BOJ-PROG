#include <bits/stdc++.h>
using namespace std;

int T, N, K, X, Y, W;
int t[1001], DP[1001];
bool solved[1001];
vector<vector<int>> dependency(1001);

int func(int x) {
  if (dependency[x].size() == 0) {
    solved[x] = true;
    return DP[x];
  }

  int mx = 0;
  for (int each : dependency[x]) {
    // 중복제거 필요 : each의 dependency가 이미 계산되어서 DP[each] 값이
    // 구해져있는 상황이면 아래에서 굳이 recursion 안 해도 됨.
    int temp;
    if (solved[each] == true)
      temp = DP[each];
    else
      temp = func(each);

    if (mx < temp) mx = temp;
  }

  DP[x] += mx;

  solved[x] = true;
  return DP[x];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  while (T-- > 0) {
    // input value setting
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
      cin >> t[i];
      DP[i] = t[i];
    }

    for (int i = 0; i < K; i++) {
      int child, parent;
      cin >> parent >> child;
      dependency[child].push_back(parent);
    }
    cin >> W;

    func(W);
    cout << DP[W] << '\n';

    for (int i = 0; i <= N; i++) dependency[i].clear();
    fill_n(solved, 1001, false);
  }

  return 0;
}