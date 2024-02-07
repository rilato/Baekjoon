// 이분 그래프는 연결된 각 노드가 서로 다른 두 가지 색으로 모두 채울 수 있는 그래프를 의미한다.

#include <iostream>
#include <vector>
#include <queue>

// RED 또는 BLUE로만 이루어져 있어야 이분 그래프. 인접한 노드가 같은 색으로 칠해진다면, 이는 이분 그래프가 아니다.
#define RED  1
#define BLUE 2

using namespace std;

int K, V, E; // 테스트 케이스, 노드, 링크 선언
vector <vector <int>> graph;
vector <int> visited;

void bfs(int start);
void dfs(int start);
bool isBipartiteGraph();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    while (K--) {
        cin >> V >> E;

        graph.resize(V + 1);
        visited.resize(V + 1);

        /* 그래프 정보 입력 */
        for (int i = 0; i < E; i++) {
            int f, s;

            cin >> f >> s;

            graph[f].push_back(s);
            graph[s].push_back(f);
        }

        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                bfs(i);
                //dfs(i);
            }
        }

        /* 이분 그래프 여부 체크 및 결과출력 */
        if (isBipartiteGraph()) {
            printf("YES\n");
        }

        else {
            printf("NO\n");
        }

        /* 그래프 및 방문기록 초기화 */
        for (int i = 0; i <= V; i++) {
            graph[i].clear();
            visited[i] = false;
        }
    }
    return 0;
}

void bfs(int start) {
    queue<int> q;

    int color = RED; // 시작 노드의 default 색상은 RED.

    visited[start] = color;
    q.push(start);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // 현재 노드와 반대되는 색깔로 바꿔놓기
        if (visited[now] == RED) {
            color = BLUE;
        }

        else if (visited[now] == BLUE) {
            color = RED;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (!visited[next]) {
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

void dfs(int start) {
    if (!visited[start]) {
        visited[start] = RED;
    }

    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];

        if (!visited[next]) {
            if (visited[start] == RED) {
                visited[next] = BLUE;
            }

            else if (visited[start] == BLUE) {
                visited[next] = RED;
            }

            dfs(next);
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];

            // 현재 보고있는 노드와 다음 노드가 같은 색으로 칠해져있다면, false를 리턴
            if (visited[i] == visited[next]) {
                return false;
            }
        }
    }

    return true;
}