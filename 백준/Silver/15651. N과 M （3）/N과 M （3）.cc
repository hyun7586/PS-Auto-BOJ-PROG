#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> selected(8);

void Input() { cin >> N >> M; }

void func(int k) {
  if (k == M) {
    for (int i = 0; i < M; i++) cout << selected[i] << ' ';
    cout << '\n';

    return;
  }

  // 아직 M-1번째 원소까지 구하지는 못 한 상태
  for (int i = 1; i <= N; i++) {
    selected[k] = i;
    func(k + 1);
    selected[k] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Input();
  func(0);

  return 0;
}