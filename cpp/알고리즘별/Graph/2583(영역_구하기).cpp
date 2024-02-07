// 오름차순으로 정답을 출력하라 했으므로 주의한다!

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int M, N, K;
int x_1, y_1, x_2, y_2;
int cnt = 0;
int map[101][101];
bool visited[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue <pair<int, int>> q;
vector <int> v;

void BFS(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;

		// 직사각형 채우기
		for (int j = M - y_2; j < M - y_1; j++) {
			for (int k = x_1; k < x_2; k++) {
				map[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			// 색칠되지 않은 부분을 탐색
			if (map[i][j] == 0 && !visited[i][j]) {
				BFS(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	// 문제에서 오름차순으로 정렬하라 했으므로 sort!!
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}

void BFS(int x, int y) {
	int count = 1;

	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;

			if (!map[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
				count++;
			}
		}
	}

	v.push_back(count);
}