#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v(100001);
int N, tmp1, tmp2;

bool comparator(pair<int, int>& a, pair<int, int>& b) {
  if (a.second == b.second) return a.first < b.first;

  return a.second < b.second;
}

void Input() {
  cin >> N;

  for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
}

void Solve() {
  Input();

  sort(v.begin(), v.begin() + N, comparator);

  for (int i = 0; i < N; i++) cout << v[i].first << " " << v[i].second << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}