// 방법 익히기..

#include <iostream>
#include <queue>

using namespace std;

int N, M, x, y;
int map[1001][1001];
bool visited[1001];
int cnt = 0;
queue <int> q;

void DFS(int v);
void BFS(int v);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> x >> y;

        map[x][y] = 1;
        map[y][x] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            //BFS(i);
            DFS(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}

void BFS(int v) {
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (map[temp][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void DFS(int v) {
    visited[v] = true;

    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && !visited[i]) {
            visited[i] = true;
            DFS(i);
        }
    }
}