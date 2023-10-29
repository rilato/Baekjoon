// ���� ����
// ���� ������ �ڱ� �ڽ��� ����Ű�� ����� ����

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector <vector <int>> v;	// ������ ����
vector <int> degree;	// ���� ���� ����
vector <int> t;			// �� ��帶�� �ɸ��� �ð� ����
vector <int> answer;	// ��� ����
queue <int> q;			// ��� ������ ���� ť

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 1���� N������ ���� index�� �°� �����ϱ� ���� N + 1�� size ����
	v.resize(N + 1);
	degree.resize(N + 1);
	t.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int time, num;

		cin >> time >> num;

		// �ǹ��� ���� ���� �ð� ����
		t[i] = time;

		while (num != -1) {
			// ����Ǵ� num�� �̾��� vector�� ���� �����ִ� i�� �ֱ�
			v[num].push_back(i);
			// i�� ���� ���� ++
			degree[i]++;

			cin >> num;
		}
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

		// ���� ���õ� �� (now)�� ����Ǿ��ִ� ��� �ֵ� ����
		for (int j = 0; j < v[now].size(); j++) {
			// Ÿ�� ���
			int next = v[now][j];

			// Ÿ�� ����� ���� ���� 1�� ����
			degree[next]--;
			// Ư�� �ǹ��� ���� ���ؼ� �ɸ��� �ð���
			// �ش� �ǹ��� ���� ���� �켱������ ����� �ϴ� �ǹ��� �߿��� ���� ���� �ɸ��� �ð� (answer[now]) + Ư�� �ǹ��� ���� ���ؼ� �ɸ��� �ð� (t[now])
			answer[next] = max(answer[next], answer[now] + t[now]);

			// ���� ������ 0�̶��, ��� ����̹Ƿ� q�� �ֱ�
			if (degree[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] + t[i] << '\n';
	}

	return 0;
}