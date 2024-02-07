#include <iostream>
#include <queue>

using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
// �밢������ ��Ÿ���� ���� dx, dy�� 8���� ���� (���ڸ� 0,0�� ������ ������ 8����)
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

		// �ʱ�ȭ �۾�
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

			// w�� y�� �����ְ�, x�� h�� ��������
			if (0 <= ny && ny < w && 0 <= nx && nx < h && !visited[nx][ny] && map[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}