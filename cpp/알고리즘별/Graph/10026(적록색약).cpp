#include <iostream>
#include <queue>

using namespace std;

int N;
char map[101][101];
bool visited[101][101];
bool RGBvisited[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cnt = 0;
int RGBcnt = 0;
queue <pair<int, int>> q;
queue <pair<int, int>> RGBq;

void BFS(int x, int y);
void RGBBFS(int x, int y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				cnt++;
			}

			if (!RGBvisited[i][j]) {
				RGBBFS(i, j);
				RGBcnt++;
			}
		}
	}

	cout << cnt << " " << RGBcnt;

	return 0;
}

void BFS(int x, int y) {
	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			// x�� ��(����) y�� ��(����)
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny] && map[tx][ty] == map[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void RGBBFS(int x, int y) {
	RGBvisited[x][y] = true;
	RGBq.push({ x, y });

	while (!RGBq.empty()) {
		int tx = RGBq.front().first;
		int ty = RGBq.front().second;

		RGBq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			// ���� ��ġ�� R �Ǵ� G�̸鼭, ���� Ȯ���� ��ġ�� ���� �湮���� �ʾҰ�, R �Ǵ� G�� ���
			if (map[tx][ty] == 'R' || map[tx][ty] == 'G') {
				if (!RGBvisited[nx][ny] && (map[nx][ny] == 'R' || map[nx][ny] == 'G')) {
					RGBvisited[nx][ny] = true;
					RGBq.push({ nx, ny });
				}
			}
			else if (map[tx][ty] == 'B') {
				if (!RGBvisited[nx][ny] && map[nx][ny] == 'B') {
					RGBvisited[nx][ny] = true;
					RGBq.push({ nx, ny });
				}
			}
		}
	}
}