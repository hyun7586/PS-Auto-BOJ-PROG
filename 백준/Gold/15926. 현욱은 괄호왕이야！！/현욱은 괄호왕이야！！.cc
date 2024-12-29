#include <bits/stdc++.h>
using namespace std;

int N;
string s;

void Input() {
  cin >> N;
  cin >> s;
}

void Solve() {
  Input();

  stack<int> st;
  bool *isCorrectString = new bool[N];
  for (int i = 0; i < N; i++) isCorrectString[i] = false;

  for (int i = 0; i < N; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      if (!st.empty()) {
        isCorrectString[i] = true;
        int index = st.top();
        st.pop();
        isCorrectString[index] = true;
      }
    }
  }

  int cnt = 0, max_value = 0;
  for (int i = 0; i < N; i++) {
    if (isCorrectString[i]) cnt += 1;

    if (isCorrectString[i] == false || i == N - 1) {
      max_value = max(max_value, cnt);
      cnt = 0;
    }
  }

  cout << max_value;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}