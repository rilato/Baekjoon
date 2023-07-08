// �Ҽ��� �ƴ� ���� �׻� sqrt(N)���� ���� ����� ����
// sqrt(N) ������ ���� ����� ��� �����ϸ� 1���� N������ �Ҽ��� ���� �� ����

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> M >> N;

	// 0��° �ε����� ������� �����Ƿ�, N + 1�� ������ ����
	vector <int> A(N + 1);

	// �ε����� �ڽ��� ���� ä���
	for (int i = 2; i <= N; i++) {
		A[i] = i;
	}

	// �Ҽ��� �ƴ� ���� �׻� sqrt(N)���� ���� ����� ����
	// sqrt(N) ������ ���� ����� ��� �����ϸ� 1���� N������ �Ҽ��� ���� �� ����
	for (int i = 2; i * i <= N; i++) {
		if (A[i] == 0)
			continue;

		// �ڽ��� ������ ������� �����Ͽ�, ��� ��� ����
		for (int j = i + i; j <= N; j += i) {
			A[j] = 0;
		}
	}

	for (int i = M; i <= N; i++) {
		if (A[i] != 0)
			cout << A[i] << '\n';
	}

	return 0;
}