#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, maxWeight = 0;
int arr[100001] = {
    0,
};

void Solve() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  sort(arr, arr + N);
  for (int i = 0; i < N; i++) maxWeight = max(maxWeight, arr[i] * (N - i));

  cout << maxWeight;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}