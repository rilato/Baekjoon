// C (����)�� ����ϱ� ���� ������ �迭�� ���� ��
// �Ľ�Į�� �ﰢ���� �̿��Ѵ�.

#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int C[31][31] = { 0, };

	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (j == 0 || i == j)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	int T, N, M;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		cout << C[M][N] << '\n';
	}
}