// 출발 점이 여러 개이므로, 출발점에 해당하는 애들에 대해 큐에 넣어준다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int answer = 0;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector <vector <int>> v;
vector <vector <bool>> visited;
vector <vector <int>> day;
queue <pair <int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    v.resize(N, vector <int>(M));
    visited.resize(N, vector <bool>(M));
    day.resize(N, vector <int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];

            if (v[i][j] == 1) {
                q.push({ i, j });
                visited[i][j] = true;
                day[i][j] = 1;
            }

            if (v[i][j] == -1) {
                day[i][j] = -1;
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M) {
                continue;
            }

            if (!visited[nr][nc] && v[nr][nc] == 0) {
                day[nr][nc] = day[r][c] + 1;
                visited[nr][nc] = true;
                q.push({ nr, nc });
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (day[i][j] == 0) {
                cout << -1;
                return 0;
            }
            else {
                answer = max(answer, day[i][j]);
            }
        }
    }

    cout << answer - 1;

    return 0;
}