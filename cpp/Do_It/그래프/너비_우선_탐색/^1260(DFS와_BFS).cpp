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

	// �湮�� �� �ִ� ��尡 ���� �� �϶����� ��ȣ�� ���� ���� ���� �湮�ϱ� ���� ����
	for (int i = 0; i < N + 1; i++)
		sort(A[i].begin(), A[i].end());

	DFS(V);

	cout << '\n';

	// �湮 �迭 �ʱ�ȭ
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
		// ��� ť�� push�� �ָ� now_node�� ����
		int now_node = q.front();

		q.pop();

		cout << now_node << " ";

		// ���� ����Ʈ�� ����Ǿ� �ִ� �ֵ��� Ž��
		// ť������ �Ķ���� v�� �ƴ�, ť���� ��� ���� �ָ� ���!!
		// ���� A[v]�� �ƴ� A[now_node]�� ���
		for (int j = 0; j < A[now_node].size(); j++) {
			int i = A[now_node][j];

			// �湮���� �ʾҴٸ�, �湮 ���θ� true�� �ٲٰ�, ť�� ���� i�� push
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}