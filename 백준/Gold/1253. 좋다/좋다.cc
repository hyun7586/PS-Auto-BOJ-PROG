#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int N, cnt = 0;
int arr[2001];

void Input() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
}

bool isPossible(int i, int target) {
  // arr[0~i-1] 범위에서 두 개 원소로 target 값을 만들 수 있는지 판단
  int left = 0, right = N - 1;

  while (left < right) {
    if (left == i) {
      left += 1;
      continue;
    }

    if (right == i) {
      right -= 1;
      continue;
    }

    if (arr[left] + arr[right] < target) {
      left += 1;
    } else if (arr[left] + arr[right] > target) {
      right -= 1;
    } else if (arr[left] + arr[right] == target) {
      return true;
    }
  }

  return false;
}

void Solve() {
  Input();

  sort(arr, arr + N);

  for (int i = 0; i < N; i++) {
    if (isPossible(i, arr[i])) {
      cnt += 1;
    }
  }

  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}