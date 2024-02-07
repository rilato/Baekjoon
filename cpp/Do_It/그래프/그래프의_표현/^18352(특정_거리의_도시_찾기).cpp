// visited 배열에 '최단' 방문 거리를 업데이트해 나간다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x;
vector <vector <int>> A;
vector <int> answer;
vector <int> visited;   // 방문 거리를 저장하는 배열

void BFS(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> x;

    A.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int s, e;

        cin >> s >> e;

        // 방향이 있는 그래프이므로, A[s].push_back(e);만 해줌
        A[s].push_back(e);
    }

    for (int i = 0; i <= n; i++) {
        visited[i] = -1;
    }

    BFS(x);

    // 방문 거리가 k인 노드의 숫자를 정답 배열에 넣기
    for (int i = 0; i <= n; i++) {
        if (visited[i] == k) {
            answer.push_back(i);
        }
    }

    if (answer.empty()) {
        cout << -1;
    }

    else {
        sort(answer.begin(), answer.end());

        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << '\n';
        }
    }

    return 0;
}

void BFS(int x) {
    queue <int> q;

    // 출발 노드 넣기
    q.push(x);
    // visited 배열에 현재 노드 방문 기록
    visited[x]++;

    while (!q.empty()) {
        // 큐에서 노드 데이터 가져오기
        int now_x = q.front();

        q.pop();

        // 현재 보고 있는 노드와 연결된 노드 i 중, 아직 방문하지 않은 경우 (visited[i] == -1),
        // visited배열에 방문 거리를 업데이트 한 후, 큐에 i push
        for (int j = 0; j < A[now_x].size(); j++) {
            int i = A[now_x][j];

            if (visited[i] == -1) {
                visited[i] = visited[now_x] + 1;
                q.push(i);
            }
        }
    }
}