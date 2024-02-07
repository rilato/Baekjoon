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
	int k = 1;		// ����

	cin >> N >> M >> R;

	vector <vector <int>> A(N + 1);	// ���� ���� �迭
	vector <bool> visited(N + 1);	// �湮 �迭
	vector <int> answer(N + 1);		// ���� ���� �迭

	for (int i = 0; i < M; i++) {
		int u, v;

		cin >> u >> v;

		A[u].push_back(v);
		A[v].push_back(u);
	}

	queue <int> q;

	for (int i = 1; i < N + 1; i++) {
		// �������� �湮�� ���� ����
		sort(A[i].begin(), A[i].end(), greater<int>());
	}

	// �� ó�� �湮�ϴ� ���� ���� q�� �ְ�, �湮 ó�� ��, ���� ���� �迭�� ����
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