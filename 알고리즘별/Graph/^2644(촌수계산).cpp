// 틀린 풀이
// 반례 : 1 1 1 1 1 1 -> 답 : 0, 내 답 : -1

#include <iostream>
#include <queue>

using namespace std;

int n, m, x, y;
int map[101][101];
bool visited[101];
queue <int> q;
int cnt = 0;
int ans = -1;

void BFS(int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x >> y >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	BFS(x);

	cout << ans;

	return 0;
}

void BFS(int x) {
	visited[x] = true;
	q.push(x);

	while (!q.empty()) {
		int tx = q.front();
		cnt++;
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[tx][i] && !visited[i]) {
				if (i == y) {
					ans = cnt;
					break;
				}

				visited[i] = true;
				q.push(i);
			}
		}
	}

	cnt = 0;
}

// 맞은 풀이
// 현재까지 이동한 거리를 하나하나 저장해나간다.

#include <iostream>
#include <queue>

using namespace std;

int n, m, x, y;
int map[101][101];
bool visited[101];
int depth[101];
queue <int> q;

void BFS(int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x >> y >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	BFS(x);

	if (!depth[y])
		cout << -1;
	else
		cout << depth[y];

	return 0;
}

void BFS(int x) {
	visited[x] = true;
	q.push(x);

	while (!q.empty()) {
		int tx = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[tx][i] && !visited[i]) {

				depth[i] = depth[tx] + 1;

				if (i == y) {
					break;
				}

				visited[i] = true;
				q.push(i);
			}
		}
	}
}