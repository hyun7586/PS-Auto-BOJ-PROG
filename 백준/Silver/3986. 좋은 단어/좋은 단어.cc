#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N, result = 0;
string str;
stack<char> st;

void Solve() {
  // input
  cin >> N;

  while (N--) {
    cin >> str;

    for (char each : str) {
      if (st.empty()) {
        st.push(each);
      } else {
        if (st.top() == each) {
          st.pop();
        } else {
          st.push(each);
        }
      }
    }

    if (st.empty()) {
      result += 1;
    }

    while (!st.empty()) st.pop();
  }

  cout << result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}