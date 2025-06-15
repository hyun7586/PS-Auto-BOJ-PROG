#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, s, e;
int S[100001] = {
    0,
};

void Input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) cin >> S[i];
}

void Solve() {
  Input();

  for (int i = 2; i <= N; i++) S[i] += S[i - 1];

  for (int i = 0; i < M; i++) {
    cin >> s >> e;
    cout << S[e] - S[s - 1] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}