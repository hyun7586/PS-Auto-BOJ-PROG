#include <bits/stdc++.h>
using namespace std;

int N, result_max, result_min;
int operands[11], temp_expression[25], temp_operators[11];
bool isUsed[11], isFirst = true;
vector<int> operators;

void solve();
void Input();
void make_expression(int k);
void compute_expression();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

void solve() {
  Input();
  make_expression(0);

  cout << result_max << '\n' << result_min;
}

void Input() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> operands[i];
  for (int i = 1; i <= 4; i++) {
    int iter;
    cin >> iter;
    for (int j = 0; j < iter; j++) operators.push_back(i);
  }

  // cout << "operators check: \n";
  // for (int each : operators) cout << each << " ";
  // cout << '\n';
}

void make_expression(int k) {
  // k : opearators 중 k번째 연산자를 결정 중이라는 소리임
  if (k == N - 1) {
    // exit conditions
    // compute the expression

    // cout << "temp_operators check: \n";
    // for (int i = 0; i < N - 1; i++) cout << temp_operators[i] << " ";
    // cout << '\n';

    compute_expression();
    return;
  }

  for (int i = 0; i < N - 1; i++) {
    if (!isUsed[i]) {
      isUsed[i] = true;
      temp_operators[k] = operators[i];

      make_expression(k + 1);

      isUsed[i] = false;
      temp_operators[k] = 0;
    }
  }
}

void compute_expression() {
  // temp_expression이 완성된 상황 : expression 계산해서 min, max값 update
  int operand1 = operands[0], operand2;

  for (int i = 0; i < N - 1; i++) {
    operand2 = operands[i + 1];

    switch (temp_operators[i]) {
      case 1:
        operand1 += operand2;
        break;
      case 2:
        operand1 -= operand2;
        break;
      case 3:
        operand1 *= operand2;
        break;
      case 4:
        if (operand1 < 0) {
          int temp = operand1 * (-1);
          operand1 = temp / operand2 * (-1);
          break;
        } else {
          operand1 /= operand2;
          break;
        }
    }
  }

  if (isFirst) {
    result_max = result_min = operand1;
    isFirst = false;
  }

  result_max = max(operand1, result_max);
  result_min = min(operand1, result_min);
}