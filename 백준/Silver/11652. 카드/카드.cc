#include <bits/stdc++.h>
using namespace std;

// pair<count, value>
vector<pair<int, long long>> cnt;
long long inputArray[100000];
int N;

void Input() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> inputArray[i];
}

void countingElements() {
  cnt.push_back(make_pair(1, inputArray[0]));

  for (int i = 1; i < N; i += 1) {
    if (inputArray[i - 1] != inputArray[i]) {
      cnt.push_back(make_pair(1, inputArray[i]));
    } else {
      cnt.back().first += 1;
    }
  }
}

bool cmp(pair<int, long long> &a, pair<int, long long> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}

void Solve() {
  Input();
  sort(inputArray, inputArray + N);
  countingElements();
  sort(cnt.begin(), cnt.end(), cmp);

  cout << cnt[0].second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}