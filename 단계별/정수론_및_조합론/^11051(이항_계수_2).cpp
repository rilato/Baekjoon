// �Ľ�Į�� �ﰢ������ ������ �� ���� ���� �Ʒ����� ������ �̿��� ����Ѵ�.

// ios::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);�� �����
// C���� ������ ������, ������ ���� �ʴ´�.

#include <iostream>

using namespace std;

int arr[1001][1001] = { 0, };

int main() {
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
		}
	}

	cout << arr[N][K];
}