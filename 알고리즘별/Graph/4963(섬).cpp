#include <iostream>
#include <queue>

using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
// 대각선까지 나타내기 위해 dx, dy를 8개로 설정 (제자리 0,0을 제외한 나머지 8방향)
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
queue <pair<int, int>> q;

void BFS(int x, int y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int cnt = 0;

		cin >> w >> h;

		if (!w && !h)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visited[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';

		// 초기화 작업
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}

	return 0;
}

void BFS(int x, int y) {
	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			// w와 y가 관계있고, x와 h가 관계있음
			if (0 <= ny && ny < w && 0 <= nx && nx < h && !visited[nx][ny] && map[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}