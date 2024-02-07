#include <iostream>
#include <vector>

using namespace std;

int N, T, P;
vector <pair <int, int>> v;
vector <int> answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// N + 1�ϱ��� ����ؾ��ϹǷ� v���� 1�� �� ������ Ȯ���Ѵ�.
	answer.resize(N + 1);

	for (int i = 0; i < N; i++) {
		cin >> T >> P;

		v.push_back({ T, P });
	}

	// i�� 0�Ϻ��� �����ϹǷ�, ���������� ��� ������ ��¥�� N - 1�̰�,
	// ����� ������ ���ڴ� N���� �����Ѵ�.
	for (int i = N - 1; i >= 0; i--) {
		if (i + v[i].first <= N) {
			answer[i] = max(answer[i + 1], v[i].second + answer[i + v[i].first]);
		}
		else {
			answer[i] = answer[i + 1];
		}
	}

	cout << answer[0];

	return 0;
}