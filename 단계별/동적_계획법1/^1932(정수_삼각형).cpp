// https://gaeunhan.tistory.com/67

// �Է� ���� ������ �迭 �ڽſ�
// ���� ���س����� ���� �����Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

// main �Լ� �ȿ� ������ �������� �ʾ�,
// long long�� ���� �� ���� main ũ���� ������ �ذ�ȴ�.
int N;
long long arr[500][500] = { 0, };
long long answer = 0;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	// N == 1�� ����� ������ �ذ����ش�.
	if (N == 1) {
		cout << arr[0][0];
		return 0;
	}

	// ���� �Էµ� �ڸ��� ��������� ������ �����Ѵ�.
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			// �� ������ ���, �� �κп��� max�� �� �ʿ䰡 ����.
			// ����� ���� �ϳ� ���̱� ����.
			if (j == 0)
				arr[i][j] = arr[i - 1][j] + arr[i][j];
			// �� �������� ���, �� �κп��� max�� �� �ʿ䰡 ����.
			// ����� ���� �ϳ� ���̱� ����.
			else if (j == i)
				arr[i][j] = arr[i - 1][j - 1] + arr[i][j];
			// ����� �ִ� ����, �� �κп��� ū ��(������� ���� �� �� ū ��)�� ����
			// ���Ͽ� �����Ѵ�.
			else
				arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];

			// ������� �Է��� �� ��, ���� ū ���� answer�� �ִ´�.
			// �ǽð����� ���� �ִ븦 ���� �����ϴ� ���̴�.
			answer = max(answer, arr[i][j]);
		}
	}

	cout << answer;
}