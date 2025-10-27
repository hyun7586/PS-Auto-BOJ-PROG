#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int T;

void Solve() {
  cin >> T;

  while (T--) {
    list<char> L;
    list<char>::iterator cursor = L.begin();

    string str;
    cin >> str;

    for (char ch : str) {
      switch (ch) {
        case '<': {
          if (cursor != L.begin()) cursor--;
          break;
        }
        case '>': {
          if (cursor != L.end()) cursor++;
          break;
        }
        case '-': {
          if (cursor != L.begin()) {
            cursor--;
            cursor = L.erase(cursor);
          }
          break;
        }
        default: {
          L.insert(cursor, ch);
          break;
        }
      }
    }

    // print
    for (char each : L) {
      cout << each;
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solve();

  return 0;
}