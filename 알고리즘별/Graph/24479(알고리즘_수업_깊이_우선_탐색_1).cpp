#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
int k = 1;		// 순서

vector <vector <int>> A;	// 간선 저장 배열
vector <bool> visited;	// 방문 배열
vector <int> answer;		// 순서 저장 배열

void DFS(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;

	A.resize(N + 1);
	visited.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;

		cin >> u >> v;

		A[u].push_back(v);
		A[v].push_back(u);
	}

	for (int i = 1; i < N + 1; i++) {
		sort(A[i].begin(), A[i].end());
	}

	answer[R] = k;
	DFS(R);

	for (int i = 1; i < N + 1; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}

void DFS(int n) {
	visited[n] = true;

	for (int j = 0; j < A[n].size(); j++) {
		if (!visited[A[n][j]]) {
			answer[A[n][j]] = ++k;
			DFS(A[n][j]);
		}
	}
}