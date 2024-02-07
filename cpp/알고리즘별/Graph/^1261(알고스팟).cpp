#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N, M;
string s;
vector<vector<int>> v;
vector<vector<int>> dijkstra;
queue<pair<int, int>> q;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(M, vector<int>(N));
    dijkstra.resize(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            v[i][j] = s[j] - '0';
            dijkstra[i][j] = INT_MAX;
        }
    }

    dijkstra[0][0] = 0;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
                continue;
            }

            // q.push({ nx, ny });를 여기서 하면 안된다! dijkstra[x][y] + 1 < dijkstra[nx][ny], dijkstra[x][y] < dijkstra[nx][ny] 조건도 확인을 거쳐야 하기 때문!

            // 다음 칸이 벽이라면,
            if (v[nx][ny] == 1) {
                // 이전 칸에서 벽 뚫은 개수 1개를 더해야 함
                if (dijkstra[x][y] + 1 < dijkstra[nx][ny]) {
                    dijkstra[nx][ny] = dijkstra[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
            // v[nx][ny] == 0
            // 다음 칸이 벽이 아니라면, 벽 뚫은 개수를 유지하며 전진
            else {
                if (dijkstra[x][y] < dijkstra[nx][ny]) {
                    dijkstra[nx][ny] = dijkstra[x][y];
                    q.push({ nx, ny });
                }
            }
        }
    }

    cout << dijkstra[M - 1][N - 1];

    return 0;
}
