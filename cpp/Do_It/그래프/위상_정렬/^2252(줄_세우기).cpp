// ���� ����
// ���� ������ �ڱ� �ڽ��� ����Ű�� ����� ����

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector <vector <int>> v;	// ������ ����
vector <int> degree;	// ���� ���� ����
queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// 1���� N������ ���� index�� �°� �����ϱ� ���� N + 1�� size ����
	v.resize(N + 1);
	degree.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E;

		cin >> S >> E;

		v[S].push_back(E);	// ��� S �ڿ� ��� E�� ����
		degree[E]++;	// ���� ���� �迭����, E�� S���� ������ �и��Ƿ�, 1 �߰�
	}

	for (int i = 1; i <= N; i++) {
		// ���� ���� �迭����, ���� 0�̶�� ����, ���� �� ���� �տ� �����ؾ� �Ѵٴ� ���� �ǹ�
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();

		q.pop();

		cout << now << " ";

		// ���� ��µ� �� (now)�� ����Ǿ��ִ� ��� �ֵ� ����
		for (int j = 0; j < v[now].size(); j++) {
			int next = v[now][j];

			// ���� ���� 1�� ����
			degree[next]--;

			// ���� ������ 0�̶��, ��� ����̹Ƿ� q�� �ֱ�
			if (degree[next] == 0) {
				q.push(next);
			}
		}

	}

	return 0;
}