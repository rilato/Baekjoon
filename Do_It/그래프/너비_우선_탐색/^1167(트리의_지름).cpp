// �ƹ� ��忡�� ���� �� ��带 ã�� �� �� ��忡�� ���� �� ��带 ã���� Ʈ���� ������ �ȴ�
// �ٿ��� ��Ʈ������ �Ÿ��߿��� �ִ밡 Ʈ���� ������ �ƴѰ�쵵 �ִ�.
// �ٸ� ���� �ϸ�, Ʈ���� ������ �ٿ��� �ٱ����� �Ÿ��ϼ��� �ִ�.


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, node, E, V;
vector <vector <pair <int, int>>> A;
vector <bool> visited;
vector <int> dist;

void BFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	A.resize(N + 1);	// 0��° index�� ������� �����Ƿ�, 100,000���� ���߱� ���ؼ��� �迭�� ũ�⸦ N + 1�� �����Ѵ�.

	for (int i = 0; i < N; i++) {
		// ��� ��ȣ �Է�
		cin >> node;

		while (1) {
			cin >> E;

			if (E == -1)
				break;

			cin >> V;

			A[node].push_back({ E, V });
		}
	}

	dist = vector <int>(N + 1, 0);	// �Ÿ� �迭 �ʱ�ȭ
	visited = vector <bool>(N + 1, 0);	// �湮 �迭 �ʱ�ȭ

	// Max ��带 ã�� ���� BFS
	BFS(1);	// 1. �ƹ� ���(1)���� ���� �� ��带 ã�´�.

	// �ε��� 1���� �����Ͱ� ���Ƿ�, max_idx�� 1���� �����ϵ��� �Ѵ�.
	// ��, 0���� �����ص� ������ �´�.
	int Max = 1;

	// Max ��� ã�� �۾�
	// for���� 0���� �����ص� ������ �´�.
	for (int i = 2; i <= N; i++) {
		// dist[i - 1]�� dist[i]�� ���ϴ� ������ �ذ��ϸ� �ȵȴ�!
		// �׷��� �Ǹ�, i�� �ε����� ���� dist���� i - 1���� ũ�⸸ �ϸ� idx�� ������Ʈ �ǹǷ�, idx�� �ִ밪�� �ƴ� �� �ֱ� �����̴�!!
		// max_idx�� i�� ���ؾ��Ѵ�!
		if (dist[Max] < dist[i]) {
			Max = i;
		}
	}

	fill(dist.begin(), dist.end(), 0); 	// �Ÿ� �迭 �ʱ�ȭ
	fill(visited.begin(), visited.end(), false);	// �湮 �迭 �ʱ�ȭ

	// Max ��忡�� ���� �� ���� ã�� ���� BFS
	// �ƹ� ��忡�� ���� �� ��带 ã�� �� (Max) �� ��忡�� ���� �� ��带 ã���� Ʈ���� ������ �ȴ�
	BFS(Max);	// �Ÿ� �迭���� ���� ū ���� �ٽ� ���������� ���� (���ο� ���������� ����)
	sort(dist.begin(), dist.end());

	cout << dist[N];	// dist�迭���� ���� ū ���� �������� ���

	return 0;
}

void BFS(int v) {
	queue <int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int now_node = q.front();
		q.pop();

		for (int j = 0; j < A[now_node].size(); j++) {
			int i = A[now_node][j].first;

			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
				dist[i] = dist[now_node] + A[now_node][j].second;				// �Ÿ� �迭 ������Ʈ
			}
		}
	}
}