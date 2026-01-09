#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int N, M, RESULT = 0;
deque<int> dq;
int elements[52] = {0};

void Input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) dq.push_back(i);

  for (int i = 0; i < M; i++) cin >> elements[i];
}

int rotate_clockwise(int goal) {
  int cnt = 0;

  while (dq.front() != goal) {
    dq.push_back(dq.front());
    dq.pop_front();
    cnt += 1;
  }

  int result = min(cnt, (int)dq.size() - cnt);
  dq.pop_front();

  return result;
}

void Solve() {
  Input();

  // main logic
  for (int i = 0; i < M; i++) {
    RESULT += rotate_clockwise(elements[i]);
  }

  cout << RESULT;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}