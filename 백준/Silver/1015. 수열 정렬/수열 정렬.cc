#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> A;
int P[50];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

void Input() {
  int input_temp;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> input_temp;
    A.push_back(make_pair(i, input_temp));
  }
}

void makeP() {
  for (int i = 0; i < N; i++) {
    P[A[i].first] = i;
  }
}

void Solve() {
  Input();
  sort(A.begin(), A.end(), cmp);
  makeP();

  for (int i = 0; i < N; i++) cout << P[i] << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}