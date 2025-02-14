#include <algorithm>
#include <iostream>

using namespace std;

int N, C;
// house 총 개수는 200,000개.
// houses[i] : i번째 집의 위치(0~1,000,000,000)
int houses[200001];

void Input() {
  cin >> N >> C;
  for (int i = 0; i < N; i++) cin >> houses[i];
}

bool isPossible(int interval) {
  // 해당 case에서 공유기 사이 최소 간격을 interval이라고 하면
  // 공유기 C개를 모두 설치할 수 있는지 판단하는 함수

  int cnt = 1;
  int prev = houses[0];

  for (int i = 1; i < N; i++) {
    if (prev + interval <= houses[i]) {
      prev = houses[i];
      cnt += 1;
    }
  }

  return cnt >= C;
}

void Solve() {
  Input();
  sort(houses, houses + N);

  int left = 0, right = *max_element(houses, houses + N), mid;
  int result = 1;

  while (left <= right) {
    mid = (left + right) / 2;

    if (isPossible(mid)) {
      result = mid;
      left = mid + 1;
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