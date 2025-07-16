#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string dp[10001];

int N;

void func(string& dp, string op1, string op2) {
  // 자릿수가 더 높은 string을 골라내는 작업
  // greaterOp에 해당하는 string의 자릿수가 더 큼.
  string greaterOp;
  string lowerOp;

  if (op1.length() >= op2.length()) {
    greaterOp = op1;
    lowerOp = op2;
  } else {
    greaterOp = op2;
    lowerOp = op1;
  }

  // cout << "greaterOp: " << greaterOp << '\n';

  // result string setting
  string result = "";
  for (int i = 0; i <= greaterOp.length(); i++) result.push_back('0');
  // cout << "result: " << result << '\n';

  for (int i = 0; i < lowerOp.length(); i++) {
    int temp = ((int)greaterOp[i] - '0') + ((int)lowerOp[i] - '0') + ((int)result[i] - '0');

    // cout << "i: " << i << ", temp: " << temp << '\n';

    result[i] = temp % 10 + '0';
    result[i + 1] = temp / 10 + '0';

    // cout << "result: " << result << '\n';
  }

  for (int i = lowerOp.length(); i < greaterOp.length(); i++) {
    int temp = ((int)greaterOp[i] - '0') + ((int)result[i] - '0');
    result[i] = temp % 10 + '0';
    result[i + 1] = temp / 10 + '0';
  }

  // result 뒤에 0 떼어주면 됨.
  while (result.back() == '0') {
    result.pop_back();
  }

  dp = result;
}

void Solve() {
  cin >> N;

  dp[0] = "0";
  dp[1] = "1";

  for (int i = 2; i <= N; i++) {
    func(dp[i], dp[i - 1], dp[i - 2]);
  }

  reverse(dp[N].begin(), dp[N].end());
  cout << dp[N];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}