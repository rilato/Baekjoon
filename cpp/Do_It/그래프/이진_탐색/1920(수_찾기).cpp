// �ð� ���⵵�� ����Ͽ�, ���� Ž���� Ȱ���Ѵ�.
// ���� Ž���� ���� ������ ���� �����̴�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector <int> A;

bool findNum(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;

		if (findNum(num))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}

bool findNum(int num) {
	int left = 0;
	int right = N - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		// A[num]�� �ƴ�, num�� ����Ѵ�!
		if (A[mid] == num) {
			return true;
		}
		else if (A[mid] < num) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return false;
}