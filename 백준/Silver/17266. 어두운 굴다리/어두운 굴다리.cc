#include <bits/stdc++.h>
using namespace std;

int N, M;
int lights[100005];
int dist[100005];

bool isPossible(int h) {
  for (int i = 0; i <= M; i++)
    if (dist[i] > 2 * h) return false;

  return true;
}

void Input() {
  cin >> N >> M;

  for (int i = 1; i <= M; i++) cin >> lights[i];

  lights[0] = 0;
  lights[M + 1] = N;

  for (int i = 0; i <= M; i++) dist[i] = lights[i + 1] - lights[i];
  dist[0] *= 2;
  dist[M] *= 2;
}

void Solve() {
  Input();

  int h = N, left = 1, right = N;
  int middle = (left + right) / 2;

  while (left <= right) {
    middle = (left + right) / 2;

    if (isPossible(middle)) {
      right = middle - 1;
      h = middle;
    } else {
      left = middle + 1;
    }
  }

  cout << h;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}