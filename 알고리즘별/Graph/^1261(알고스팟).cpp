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

            // q.push({ nx, ny });�� ���⼭ �ϸ� �ȵȴ�! dijkstra[x][y] + 1 < dijkstra[nx][ny], dijkstra[x][y] < dijkstra[nx][ny] ���ǵ� Ȯ���� ���ľ� �ϱ� ����!

            // ���� ĭ�� ���̶��,
            if (v[nx][ny] == 1) {
                // ���� ĭ���� �� ���� ���� 1���� ���ؾ� ��
                if (dijkstra[x][y] + 1 < dijkstra[nx][ny]) {
                    dijkstra[nx][ny] = dijkstra[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
            // v[nx][ny] == 0
            // ���� ĭ�� ���� �ƴ϶��, �� ���� ������ �����ϸ� ����
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
