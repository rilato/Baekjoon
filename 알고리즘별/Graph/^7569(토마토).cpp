// 연결 요소의 개수를 세는 방식이 아닌,
// 최단 거리를 구하는 방식이 사용됨

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, H;
int map[101][101][101];
int day = 0;
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
queue <pair <pair<int, int>, int>> q;

void BFS();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];

				if (map[i][j][k] == 1) {
					q.push({ { i, j }, k });
				}
			}
		}
	}

	BFS();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}

				else {
					day = max(map[i][j][k], day);
				}
			}

		}
	}

	cout << day - 1;

	return 0;
}

void BFS() {
	while (!q.empty()) {
		int tz = q.front().first.first;
		int ty = q.front().first.second;
		int tx = q.front().second;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = tz + dz[i];
			int ny = ty + dy[i];
			int nx = tx + dx[i];

			if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M)
				continue;

			if (map[nz][ny][nx] == 0) {
				map[nz][ny][nx] = map[tz][ty][tx] + 1; // 거리 + 1
				q.push({ { nz, ny }, nx });
			}
		}
	}
}




// 또 다른 풀이

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, h;
int tomato[101][101][101];

int dz[6] = { 0,0,0 ,0,-1,1 };
int dx[6] = { 0,0 ,1,-1,0,0 };
int dy[6] = { -1,1,0,0,0,0 };

int dist[101][101][101];
int day = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	queue<pair<pair<int, int>, int>> Q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];

				if (tomato[i][j][k] == 1)
					Q.push({ { i, j }, k });

				// -1을 넣는 이유는, 마지막에 day - 1로 day를 나타내지 않기 위함
				if (tomato[i][j][k] == 0)
					dist[i][j][k] = -1;
			}
		}
	}
	while (!Q.empty()) {
		int tz = Q.front().first.first;
		int tx = Q.front().first.second;
		int ty = Q.front().second;

		Q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = tz + dz[i];
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
				continue;

			if (dist[nz][nx][ny] >= 0)
				continue;

			dist[nz][nx][ny] = dist[tz][tx][ty] + 1;
			Q.push({ { nz, nx }, ny });
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}

				day = max(day, dist[i][j][k]);
			}
		}
	}

	// 위에서 애초에 -1을 넣었기 때문에 day - 1이 아닌 day로 정답 표기
	cout << day;
}