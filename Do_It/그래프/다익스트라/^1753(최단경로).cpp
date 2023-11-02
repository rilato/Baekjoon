#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K, u, v, w;
	vector <vector <pair <int, int>>> A;		// ��������� {������, ������ ����ġ}�� ���� (2���� ����)
	vector <int> distance;			// �ִ� ��� �Ÿ��� ������ ����
	vector <bool> visited;			// ��� ��� ���� ����
	// priority_queue�� �⺻������ ���� ū ������ Top()���� ������.
	// ���ͽ�Ʈ�󿡼�, ���� ���� ������ �����ϱ� ����, priority_queue�� ���ڸ� �� ���� �ְ�, greater�� ��.
	priority_queue<pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;		// ���ͽ�Ʈ�� �˰��� ������ ���� �켱���� ť(�������� ����)

	cin >> V >> E >> K;

	A.resize(V + 1);
	distance.resize(V + 1);
	visited.resize(V + 1);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		A[u].push_back({ v, w });
	}

	// �ִ� ��� �Ÿ� ���� �ʱ�ȭ
	for (int i = 0; i <= V; i++) {
		distance[i] = 2147000000;
	}

	distance[K] = 0;	// ��� ������ distance�� 0���� �ʱ�ȭ
	pq.push({ 0, K });	// ��� ��带 �켱���� ť�� �ְ� ����. �켱���� ť�� ({ �ش� ����� distance��, �ش� ��� })�� ����

	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();

		int temp_vertex = temp.second;	// ���� ������ ���

		// ���� ������ ��带 �湮�� ���� �ִ��� Ȯ��
		if (visited[temp_vertex]) {
			// �̹� �湮�� ���� �ٽ� ť�� ���� ����
			continue;
		}

		// ���� ��带 �湮 ���� ������Ʈ
		visited[temp_vertex] = true;

		// ���� ���� ����� ���� ������ŭ iterate
		for (int i = 0; i < A[temp_vertex].size(); i++) {
			pair<int, int> tmp = A[temp_vertex][i];
			int next = tmp.first;	// ����� ���� ���
			int value = tmp.second;	// ���� ��

			// Ÿ�� ��带 �湮���� �ʾҰ� ���� ���� ��� �ִ� �Ÿ� + ��� < Ÿ�� ����� �ִܰŸ��� ���, ������Ʈ ����
			if (distance[temp_vertex] + value < distance[next]) {
				distance[next] = value + distance[temp_vertex];
				pq.push({ distance[next], next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (visited[i])
			cout << distance[i] << '\n';
		else
			cout << "INF" << '\n';
	}

	return 0;
}