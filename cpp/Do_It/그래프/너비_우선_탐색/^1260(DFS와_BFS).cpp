#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
vector <vector <int>> A;
vector <bool> visited;

void DFS(int v);
void BFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;

	A.resize(N + 1);
	visited = vector <bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		int s, e;

		cin >> s >> e;

		A[s].push_back(e);
		A[e].push_back(s);
	}

	// 방문할 수 있는 노드가 여러 개 일때에는 번호가 작은 것을 먼저 방문하기 위해 정렬
	for (int i = 0; i < N + 1; i++)
		sort(A[i].begin(), A[i].end());

	DFS(V);

	cout << '\n';

	// 방문 배열 초기화
	fill(visited.begin(), visited.end(), false);

	BFS(V);

	return 0;
}

void DFS(int v) {
	cout << v << " ";

	visited[v] = true;

	for (int j = 0; j < A[v].size(); j++) {
		int i = A[v][j];

		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	queue <int> q;

	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		// 방금 큐에 push한 애를 now_node에 저장
		int now_node = q.front();

		q.pop();

		cout << now_node << " ";

		// 인접 리스트에 연결되어 있는 애들을 탐색
		// 큐에서는 파라미터 v가 아닌, 큐에서 방금 꺼낸 애를 사용!!
		// 따라서 A[v]가 아닌 A[now_node]를 사용
		for (int j = 0; j < A[now_node].size(); j++) {
			int i = A[now_node][j];

			// 방문하지 않았다면, 방문 여부를 true로 바꾸고, 큐에 현재 i를 push
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}