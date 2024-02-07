#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	int k = 1;		// 순서

	cin >> N >> M >> R;

	vector <vector <int>> A(N + 1);	// 간선 저장 배열
	vector <bool> visited(N + 1);	// 방문 배열
	vector <int> answer(N + 1);		// 순서 저장 배열

	for (int i = 0; i < M; i++) {
		int u, v;

		cin >> u >> v;

		A[u].push_back(v);
		A[v].push_back(u);
	}

	queue <int> q;

	for (int i = 1; i < N + 1; i++) {
		// 내림차순 방문을 위한 정렬
		sort(A[i].begin(), A[i].end(), greater<int>());
	}

	// 맨 처음 방문하는 수에 대해 q에 넣고, 방문 처리 후, 순서 저장 배열에 저장
	q.push(R);
	visited[R] = true;
	answer[R] = k;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int j = 0; j < A[now].size(); j++) {
			if (!visited[A[now][j]]) {
				q.push(A[now][j]);
				visited[A[now][j]] = true;
				answer[A[now][j]] = ++k;
			}
		}
	}

	for (int i = 1; i < N + 1; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}