#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, X, cnt = 0;
int a[100005] = {0};
bool isPresent[1000005] = {false};

void Solve() {
  // initial input
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
    isPresent[a[i]] = true;
  }

  cin >> X;

  // check if `X-a[i]` exists
  for (int i = 0; i < N; i++) {
    if (X - a[i] >= 1000000 || X - a[i] == a[i] || X - a[i] < 0) continue;

    if (isPresent[X - a[i]]) {
      cnt++;
    }
  }

  // print cnt
  cout << cnt / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solve();

  return 0;
}