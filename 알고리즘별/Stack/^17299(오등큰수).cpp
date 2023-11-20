#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector <int> v;
	vector <int> cnt;
	vector <int> answer;
	stack <int> s;

	cin >> N;

	v.resize(N);
	answer.resize(N, -1);
	cnt.resize(1000001, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];

		cnt[v[i]]++;
	}

	for (int i = 0; i < N; i++) {
		// ������ ���� �ʾҰ�, ���� ������ cnt���� ���� top ��ġ�� ���� ���� cnt���� ũ�ٸ�
		while (!s.empty() && cnt[v[s.top()]] < cnt[v[i]]) {
			answer[s.top()] = v[i];	// ���� �����ִ� ��(����ū��)�� answer �迭�� ����
			s.pop();				// ������ top�� ����
		}

		s.push(i);
	}

	for (int ans : answer) {
		cout << ans << " ";
	}

	return 0;
}