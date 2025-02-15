#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100000];

void Input() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
}

void Solve() {
  Input();

  sort(arr, arr + N);

  int left = 0, right = N - 1;
  int result_sum = INT_MAX, result_left = 0, result_right = N - 1;

  while (left < right) {
    if (result_sum > abs(arr[right] + arr[left])) {
      result_sum = abs(arr[right] + arr[left]);
      result_left = left;
      result_right = right;
    }

    if (arr[left] + arr[right] < 0) {
      left += 1;
    } else if (arr[left] + arr[right] > 0) {
      right -= 1;
    } else {
      // exit immediately
      cout << arr[left] << " " << arr[right] << '\n';
      return;
    }
  }

  cout << arr[result_left] << " " << arr[result_right] << '\n';

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}