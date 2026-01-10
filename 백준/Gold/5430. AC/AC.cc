#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, N;
string operations;
string numbers;
deque<int> dq;

void Input() {
  cin >> operations >> N >> numbers;

  string numb = "";
  for (char each : numbers) {
    if (each == '[') {
      continue;
    } else if (each == ',' || each == ']') {
      if (numb.size() > 0) dq.push_back(stoi(numb));
      numb = "";
    } else {
      // 그냥 숫자
      numb += each;
    }
  }
}

void printDQ(bool isFront, int dqSize) {
  cout << '[';

  if (isFront) {
    for (int i = 0; i < dqSize; i++) {
      cout << dq.front();
      dq.pop_front();

      if (i < dqSize - 1) cout << ',';
    }

  } else {
    for (int i = dqSize - 1; i >= 0; i--) {
      cout << dq.back();
      dq.pop_back();

      if (i > 0) cout << ',';
    }
  }

  cout << "]\n";
}

void Solve() {
  cin >> T;

  while (T--) {
    dq.clear();
    Input();

    // main logic
    bool isFront = true;

    int deletions = 0;
    for (auto each : operations)
      if (each == 'D') deletions += 1;

    if (deletions > N) {
      cout << "error\n";
      continue;
    }

    for (char each : operations) {
      if (each == 'R') {
        if (isFront)
          isFront = false;
        else
          isFront = true;
      } else {
        if (isFront) {
          dq.pop_front();
        } else {
          dq.pop_back();
        }
      }
    }

    printDQ(isFront, dq.size());
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}