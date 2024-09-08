#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> characters;
char temp[15];

void Input() {
  cin >> L >> C;

  char temp;
  for (int i = 0; i < C; i++) {
    cin >> temp;
    characters.push_back(temp);
  }
}

bool isValid(char* target) {
  // n개의 문자를 다 채운 target 배열이 모음 1개 이상 & 자음 2개 이상 조건을
  // 만족하는지 체크
  int vowel_cnt = 0, consonant_cnt = 0;

  for (int i = 0; i < L; i++) {
    if (target[i] == '0')
      cout << "\nwrong string:\n";
    else if (target[i] == 'a' || target[i] == 'e' || target[i] == 'i' ||
             target[i] == 'o' || target[i] == 'u')
      vowel_cnt += 1;
    else
      consonant_cnt += 1;
  }

  if (vowel_cnt >= 1 && consonant_cnt >= 2) return true;

  return false;
}

void func(int n, int prev_index) {
  // n번째 문자를 결정하는 함수
  if (n == L) {
    // exit conditions
    if (isValid(temp)) {
      for (int i = 0; i < L; i++) cout << temp[i];
      cout << '\n';
    }

    return;
  }

  for (int i = prev_index + 1; i < C; i++) {
    temp[n] = characters[i];
    func(n + 1, i);
    temp[n] = '0';
  }
}

void Solve() {
  Input();
  sort(characters.begin(), characters.end());
  func(0, -1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}