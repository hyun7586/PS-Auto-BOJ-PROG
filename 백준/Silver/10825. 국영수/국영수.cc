#include <bits/stdc++.h>
using namespace std;

int N;
vector<tuple<int, int, int, string>> students;

bool cmp(tuple<int, int, int, string> &v1, tuple<int, int, int, string> &v2) {
  // def: 국어 성적 다른 경우
  if (get<0>(v1) != get<0>(v2)) {
    return get<0>(v1) > get<0>(v2);
  } else {
    // case1: 국어 성적 동일, 영어 성적 다름
    if (get<1>(v1) != get<1>(v2)) {
      return get<1>(v1) < get<1>(v2);
    } else {
      // case2: 국어 성적 동일, 영어 성적 동일, 수학 성적 다름
      if (get<2>(v1) != get<2>(v2)) {
        return get<2>(v1) > get<2>(v2);
      } else {
        // case4: 국어 성적 동일, 영어 성적 동일, 수학 성적 동일, 이름 다름
        return get<3>(v1) < get<3>(v2);
      }
    }
  }
}

void Input() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    string name;
    int kor, eng, mat;
    cin >> name >> kor >> eng >> mat;

    students.push_back(make_tuple(kor, eng, mat, name));
  }
}

void Solve() {
  Input();
  sort(students.begin(), students.end(), cmp);

  for (auto each : students) {
    cout << get<3>(each) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}