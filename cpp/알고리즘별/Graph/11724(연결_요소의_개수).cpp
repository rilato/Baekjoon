#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b;
int cnt = 0;
vector <vector <int>> v;
vector <bool> visited;

void BFS(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			BFS(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}

void BFS(int num) {
	queue <int> q;
	q.push(num);
	visited[num] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int idx = v[now][i];

			if (!visited[idx]) {
				visited[idx] = true;
				q.push(idx);
			}
		}
	}
}