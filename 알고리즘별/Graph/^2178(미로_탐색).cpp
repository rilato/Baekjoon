// https://wooono.tistory.com/410

// DFS와 BFS방식이 있는데, 최단경로는 BFS가 적합하다.
// DFS알고리즘 특성상 최단거리를 찾으려면 완전 탐색을 하고 그중에서 가장 작은 값을 선택해야 하는데 경로가 아주 많을 수 있으므로 시간 복잡도가 매우 커진다.
// 반면 BFS는 최단거리를 보장하기 때문에 이러한 문제들(최단거리 구하기)은 BFS로 풀어야 한다.

#include <iostream>
#include <queue>

using namespace std;

int N, M;
string s;
int map[101][101];
int	dist[101][101];
bool visited[101][101];
int move_x[4] = { -1, 1, 0, 0 };
int move_y[4] = { 0, 0, -1, 1 };
int minimum = 10001;
queue <pair <int, int>> q;

void DFS(int x, int y, int depth);
void BFS(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s;

		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	//DFS(0, 0, 1);

	//cout << minimum;

	BFS(0, 0);

	cout << dist[N - 1][M - 1];

	return 0;
}

void DFS(int x, int y, int depth) {
	//맵의 범위를 벗어 날때
	if (x < 0 || y < 0 || x >= N || y >= M)
		return;

	// 도착할 때
	if (x == N - 1 && y == M - 1) {
		if (depth < minimum)
			minimum = depth;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int Next_x = x + move_x[i];
		int Next_y = y + move_y[i];

		if (visited[Next_x][Next_y] == 0 && map[Next_x][Next_y] == 1) {
			visited[Next_x][Next_y] = 1;
			DFS(Next_x, Next_y, depth + 1);
			visited[Next_x][Next_y] = 0;
		}
	}
}

void BFS(int x, int y) {
	visited[x][y] = 1;
	q.push({ x, y });
	dist[x][y]++;

	while (!q.empty()) {
		int temp_x = q.front().first;
		int temp_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_x = temp_x + move_x[i];
			int next_y = temp_y + move_y[i];

			if ((0 <= next_x && next_x < N) && (0 <= next_y && next_y < M) && (!visited[next_x][next_y] && map[next_x][next_y] == 1)) {
				visited[next_x][next_y] = 1;
				q.push({ next_x, next_y });
				dist[next_x][next_y] = dist[temp_x][temp_y] + 1;
			}
		}
	}
}