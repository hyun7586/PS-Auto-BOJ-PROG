#include <bits/stdc++.h>
using namespace std;

// 사다리 개수: N, 뱀 개수: M
int N, M;
// 사다리 표현: ladders[i]=j: i칸 -> j칸 사다리 존재(i<j)
int ladders[101] = {0};
// 뱀 표현: snakes[i]=j: i칸 -> j칸 뱀 존재(i>j)
int snakes[101] = {0};
// visited check: BFS 방식으로 경우의 수를 순회한다면 이미 방문한 칸에 다시 방문하는 queue는 무조건 비효율적임
// 나중에 같은 칸에 방문한 queue의 이동수는 무조건적으로 큼 (나중에 들어온 queue는 고려할 필요 없음)
bool visited[101];

queue<pair<int, int>> q;

void Input() {
  int start, end;

  cin >> N >> M;

  // ladders: N
  for (int i = 0; i < N; i++) {
    cin >> start >> end;
    ladders[start] = end;
  }

  // snakes: M
  for (int i = 0; i < M; i++) {
    cin >> start >> end;
    snakes[start] = end;
  }
}

void modified_bfs() {
  // 1칸에서 시작, cnt==0
  q.push(make_pair(1, 0));

  // 기본 BFS 틀: q.empty()까지 반복
  while (!q.empty()) {
    pair<int, int> x = q.front();
    q.pop();

    // queue에 들어갈 때 visited check 안 되었으면 실제로 방문할 때 visited check
    if (visited[x.first] == false) {
      //cout << "visited check\n";
      visited[x.first] = true;
    }

    // bound check: queue에 넣을 때도 체크하긴 함
    if (x.first > 100) continue;

    // bfs 순회 중에 먼저 100칸에 도달한 queue가 무조건 최적임: 출력하고 exit하면 됨.
    if (x.first == 100) {
      cout << x.second;
      return;
    }

    // 현재 칸에서 주사위를 던지므로 전방 6칸에 대해서 모두 조사
    for (int i = 1; i <= 6; i++) {
      // 다음 방문할 칸
      int next = x.first + i;

      // bound check
      if (next > 100) continue;

      // 각 다음 칸에 대해서 visited check도 필요함

      // case 1: next칸에 사다리가 있는 경우
      if (ladders[next] != 0) {
        if (visited[ladders[next]] == false) {
          q.push(make_pair(ladders[next], x.second + 1));
          visited[next] = true;
          visited[ladders[next]] = true;
        }
      }

      // case 2: next칸에 뱀이 있는 경우
      else if (snakes[next] != 0) {
        if (visited[snakes[next]] == false) {
          q.push(make_pair(snakes[next], x.second + 1));
          visited[next] = true;
          visited[snakes[next]] = true;
        }
      }

      // case 3: next칸에 일반 칸인 경우
      else {
        if (visited[next] == false) {
          q.push(make_pair(next, x.second + 1));
          visited[next] = true;
        }
      }
    }
  }
}

void Solve() {
  Input();
  modified_bfs();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}
