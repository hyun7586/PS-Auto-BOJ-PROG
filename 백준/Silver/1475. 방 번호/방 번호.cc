#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int max_val = 0;
int cnt[10] = {0};

void Solve() {
  cin >> N;

  // fill the cnt array
  while (N > 0) {
    cnt[N % 10] += 1;
    N = N / 10;
  }

  // find the max index/value element from the cnt array
  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9) continue;

    max_val = max(max_val, cnt[i]);
  }

  cout << max(max_val, (cnt[6] + cnt[9] + 1) / 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solve();

  return 0;
}