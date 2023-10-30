// ���� ����
// ���� ������ �ڱ� �ڽ��� ����Ű�� ����� ����

// ��� ���ÿ� ���� ���ð� �־����� ������ �Ϲ����� ���� ������ �ƴ�, �������� ��� ���÷� �����ϰ� ���� ������ �����ؾ� ��.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, e, t;			// s : start, e : end, t : time
vector <vector <pair<int, int>>> A;		// ������ ���� �迭
vector <vector <pair<int, int>>> reverseA;	// ������ ���� ����Ʈ ������ ���� �迭
vector <int> degree;		// ���� ���� �迭
vector <int> answer;
queue <int> q;				// ���� ������ ������ ť

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	A.resize(n + 1);
	reverseA.resize(n + 1);
	degree.resize(n + 1);
	answer.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> s >> e >> t;

		A[s].push_back({ e, t });
		reverseA[e].push_back({ s, t });	// ������ ���� ���� ����
		degree[e]++;	// ���� ���� �迭 + 1
	}

	int start, end;

	cin >> start >> end;

	// ���� ����

	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int j = 0; j < A[now].size(); j++) {
			pair<int, int> next = A[now][j];

			degree[next.first]--;

			answer[next.first] = max(answer[next.first], answer[now] + next.second);

			if (degree[next.first] == 0) {
				q.push(next.first);
			}
		}
	}

	// ���� ���� reverse

	int cnt = 0;			// 1�е� ���� �ʰ� �޷��� �ϴ� ������ ��
	vector <bool> visited;	// �� ������ �湮 �迭 ����
	visited.resize(n + 1);
	queue <int> rq;

	rq.push(e);				// ���� ���� ť�� ����

	while (!rq.empty()) {
		int now = rq.front();
		rq.pop();

		for (int j = 0; j < reverseA[now].size(); j++) {
			// 1�е� ���� �ʴ� ���� üũ
			pair <int, int> next = reverseA[now][j];

			if (answer[next.first] + next.second == answer[now]) {
				// ���� �ʰ� �޷����ϴ� ���� �� 1 �߰�
				cnt++;
				// �ߺ� ī��Ʈ ������ ���� �̹� �湮�� ��� ����
				if (visited[next.first] == false) {
					visited[next.first] = true;
					rq.push(next.first);
				}
			}
		}
	}

	cout << answer[end] << '\n' << cnt;

	return 0;
}