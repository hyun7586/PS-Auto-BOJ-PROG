#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, S = 0;
int A[51], B[51];

void Input() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
}

void Solve() {
  Input();

  sort(A, A + N);
  sort(B, B + N);

  for (int i = 0; i < N; i++) {
    S += A[i] * B[N - i - 1];
  }

  cout << S;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}