#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> st1;
stack<int> st2;
int sequence[100005] = {0};
vector<char> result;

void Input() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> sequence[i];
    st1.push(N - i);
  }
}

void Solve() {
  Input();

  for (int i = 0; i < N; i++) {
    while (!st1.empty() && st1.top() <= sequence[i]) {
      st2.push(st1.top());
      result.push_back('+');
      st1.pop();
    }

    if (!st2.empty() && st2.top() == sequence[i]) {
      st2.pop();
      result.push_back('-');
    } else if (!st2.empty() && st2.top() != sequence[i]) {
      cout << "NO\n";
      return;
    }
  }

  for (auto each : result) {
    cout << each << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solve();

  return 0;
}