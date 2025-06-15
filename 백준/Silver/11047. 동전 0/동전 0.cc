#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K, result = 0;
int arr[10] = {
    0,
};

void Solve() {
  // input
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> arr[i];

  // main logic
  for (int i = N - 1; i >= 0; i--) {
    while (K >= arr[i]) {
      K -= arr[i];
      result += 1;
    }
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