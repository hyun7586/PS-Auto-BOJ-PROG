#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>> max_heap;
priority_queue<int, vector<int>, greater<>> min_heap;

void Solve() {
  int input;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> input;

    if (max_heap.empty() || input <= max_heap.top())
      max_heap.push(input);
    else if (input > max_heap.top() || max_heap.size() > min_heap.size() - 1)
      min_heap.push(input);

    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }

    if (max_heap.size() < min_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }

    cout << max_heap.top() << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}