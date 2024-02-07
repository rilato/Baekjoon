#include <iostream>
#include <queue>

using namespace std;

int T, M, N, K, X, Y;
int cnt = 0;
int arr[51][51];
bool visited[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue <pair<int, int>> q;

void BFS(int x, int y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--) {
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			// 가로가 열이고, 세로가 행이므로 Y와 X를 뒤집어서 받도록 한다.
			cin >> Y >> X;

			arr[X][Y] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1 && !visited[i][j]) {
					cnt++;
					BFS(i, j);
				}
			}
		}

		cout << cnt << '\n';

		cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = 0;
				visited[i][j] = false;
			}
		}

		while (!q.empty())
			q.pop();
	}

	return 0;
}

void BFS(int x, int y) {
	visited[x][y] = 1;
	q.push({ x, y });

	while (!q.empty()) {
		int temp_x = q.front().first;
		int temp_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = temp_x + dx[i];
			int next_y = temp_y + dy[i];

			if ((0 <= next_x && next_x < N) && (0 <= next_y && next_y < M) && (!visited[next_x][next_y]) && arr[next_x][next_y] == 1) {
				visited[next_x][next_y] = true;
				q.push({ next_x, next_y });
			}
		}
	}
}