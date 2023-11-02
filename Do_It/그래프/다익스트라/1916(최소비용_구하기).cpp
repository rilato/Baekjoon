#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, start, end;
	vector <vector <pair <int, int>>> A;
	vector <bool> visited;
	priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;
	vector <int> distance;

	cin >> N >> M;

	A.resize(N + 1);
	visited.resize(N + 1);
	distance.resize(N + 1);

	// �׷��� ����
	for (int i = 0; i < M; i++) {
		int s, e, w;

		cin >> s >> e >> w;

		A[s].push_back({ e, w });
	}

	// ��� ����, ���� ���� �Է�
	cin >> start >> end;

	// �Ÿ� �迭 �ʱ�ȭ
	for (int i = 0; i <= N; i++) {
		distance[i] = 2000000000;
	}

	distance[start] = 0;
	// start��, start�� distance[start]���� Ǫ��
	// ��� ���� ������ ����, ������ ������ {���, ���}�� ����
	pq.push({ 0, start });

	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();
		int temp_node = temp.second;

		// �ش� ��带 �湮�� ���� ������, �ǳ� �ٱ�
		if (visited[temp_node])
			continue;

		visited[temp_node] = true;

		for (int i = 0; i < A[temp_node].size(); i++) {
			int next_node = A[temp_node][i].first;
			int weight = A[temp_node][i].second;

			// ���� ����� �Ÿ� + ���� �������� ����ġ < ���� ����� �ִ� �Ÿ����, �� ������Ʈ
			if (distance[temp_node] + weight < distance[next_node]) {
				distance[next_node] = distance[temp_node] + weight;
				pq.push({ distance[next_node], next_node });
			}
		}
	}

	cout << distance[end];

	return 0;
}