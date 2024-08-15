#include <bits/stdc++.h>
using namespace std;

int N, S, cnt = 0;
int arr[20];

void Input() {
  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> arr[i];
}

void rec_func(int k, int sum) {
  // arr[k] 원소를 포함할지/제외할지를 결정하는 함수
  if (k == N) {
    if (sum == S) cnt += 1;
    return;
  }

  rec_func(k + 1, sum + arr[k]);
  rec_func(k + 1, sum);
}

void solve() {
  Input();
  rec_func(0, 0);

  // S==0이면 아무 원소도 선택하지 않으면서 정답조건을 충족하는 case도
  // counting됨 -> 하나 빼 줘야 함
  if (S == 0) cnt -= 1;

  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}