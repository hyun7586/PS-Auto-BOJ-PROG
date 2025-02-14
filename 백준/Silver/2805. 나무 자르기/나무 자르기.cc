#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> wood;

void Input() {
  cin >> N >> M;

  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    wood.push_back(temp);
  }
}

bool isPossible(int mid) {
  long long cnt = 0;

  for (int i = 0; i < N; i++) {
    if (wood[i] - mid > 0) cnt += wood[i] - mid;
  }

  return cnt >= M;
}

void Solve() {
  Input();

  int left = 0, right = INT_MAX, mid;
  int result = 0;

  while (left <= right) {
    mid = (left + right) / 2;

    if (isPossible(mid)) {
      left = mid + 1;
      result = mid;
    } else {
      right = mid - 1;
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