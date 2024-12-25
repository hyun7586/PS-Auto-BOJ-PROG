#include <bits/stdc++.h>
using namespace std;

int N;
// pair<original_index, value>
deque<pair<int, int>> dq;

void Input() {
  int temp;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    dq.push_back(make_pair(i + 1, temp));
  }
}

void Solve() {
  Input();

  while (dq.size() != 0) {
    auto it = dq.front();
    dq.pop_front();

    cout << it.first << " ";

    // it.second는 0이 아님
    if (it.second > 0) {
      for (int i = 0; i < it.second - 1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      for (int i = 0; i < (-1) * it.second; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }
}

int main() {
  Solve();

  return 0;
}