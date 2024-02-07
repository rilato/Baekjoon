// DFS BFS 모두 사용해서 풀어봤음

#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

int N, M; //정점개수, 간선개수, 시작정점
int map[MAX][MAX]; //인접 행렬 그래프
bool visited[MAX]; //정점 방문 여부
int cnt = 0;
queue<int> q;

void reset();
void DFS(int v);
//void BFS(int v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;

        cin >> a >> b;

        // a와 b가 인접해있으면 (a,b) 와 (b,a) 모두 행렬에서 1로 설정
        map[a][b] = 1;
        map[b][a] = 1;
    }

    DFS(1);

    //cout << cnt << '\n';

    //cnt = 0;

    //reset();
    //BFS(1);

    cout << cnt;

    return 0;
}

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void DFS(int v) {
    // 인자로 받은 현재의 점은 방문한 상태이므로 true로 변경
    visited[v] = true;

    // N은 노드의 개수
    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
            ++cnt;
            DFS(i);
        }
    }
}

void BFS(int v) {
    // 인자로 받은 현재의 점을 큐에 푸시
    q.push(v);
    // 방문한 상태이므로 true로 변경
    visited[v] = true;

    // 큐가 차있는 동안 계속 진행
    while (!q.empty()) {
        v = q.front();

        q.pop();

        // N은 노드의 개수
        for (int i = 1; i <= N; i++) {
            if (map[v][i] == 1 && visited[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
                ++cnt;
                // 그 애를 큐에 푸시
                q.push(i);
                // 방문했다고 표시
                visited[i] = true;
            }
        }
    }
}