#include <iostream>
#include <queue>

using namespace std;

int T, l, x, y, fnX, fnY;
int maxi = 0;
int cnt = 0;
int ans = 1;
int map[301][301];
bool visited[301][301];
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
queue <pair<int, int>> q;

void BFS(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> l >> x >> y >> fnX >> fnY;

		visited[x][y] = true;
		q.push({ x, y });

		BFS(x, y);

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
	}

	return 0;
}

void BFS(int x, int y) {
	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;

		q.pop();

		// nx == fnX가 아닌 tx == fnX를 해야하는 이유는
		// 맨 처음 말이 시작하는 지점과 맨 마지막에 말이 도착하는 지점이 같을 경우,
		// 한 칸도 말을 움직이지 않기 때문이다.
		// ny로 들어가는 순간, 말이 최소 한 번 움직인 것이다.
		if (tx == fnX && ty == fnY) {
			cout << map[tx][ty] << '\n';
		}

		for (int i = 0; i < 8; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= l || ny < 0 || ny >= l)
				continue;

			if (!visited[nx][ny]) {
				map[nx][ny] = map[tx][ty] + 1;
				visited[nx][ny] = true;
				q.push({ nx, ny });

			}
		}
	}
}