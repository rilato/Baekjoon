#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
string S;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector <vector <pair <int, int>>> v;	// first는 입력 값, second는 cnt값
vector <vector <bool>> visited;

void BFS(int row, int col, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v.resize(N, vector <pair <int, int>>(M));
	visited.resize(N, vector <bool>(M));

	for (int i = 0; i < N; i++) {
		cin >> S;

		for (int j = 0; j < M; j++) {
			v[i][j].first = S[j] - '0';
			v[i][j].second = 0;
		}
	}

	BFS(0, 0, 0);

	return 0;
}

void BFS(int row, int col, int cnt) {
	queue <pair <pair <int, int>, int>> q;

	v[row][col].second = 1;
	q.push({ {row, col}, cnt + 1 });
	visited[row][col] = true;

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int count = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M || v[nr][nc].first == 0) {
				continue;
			}

			if (!visited[nr][nc]) {
				v[nr][nc].second = count + 1;
				q.push({ { nr, nc }, count + 1 });
				visited[nr][nc] = true;
			}
		}
	}

	cout << v[N - 1][M - 1].second;
}
