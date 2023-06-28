// ���� Ž������ �߾Ӱ����� ���� ���� ������ ���鼭 ������ ���ݾ� ���̴� ������� B[k]�� ���Ѵ�.
// ��, ���� ���� ������ k - 1���� �߾Ӱ��� �����̴�.

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

long long findNum(int left, int right);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	// ���� �Է� �޴� ����, 10^5 * 10^5 => �ð��ʰ�
	//for (long long i = 0; i < N; i++) {
	//	for (long long j = 0; j < N; j++) {
	//		A[i * (N - 1) + j] = i * j;
	//	}
	//}

	cout << findNum(1, K);

	return 0;
}

long long findNum(int left, int right) {
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long cnt = 0;

		// �߾Ӱ����� ���� ���� �� ������ ���
		for (int i = 1; i <= N; i++) {
			// B[K]���� ���� ���� ī��Ʈ�ϴ� �ٽ� ����
			cnt += min(mid / i, N);
		}

		if (cnt < K) {
			left = mid + 1;
		}
		else {
			// ���� �ܰ��� �߾� ���� ans�� ����
			ans = mid;
			right = mid - 1;
		}
	}

	return ans;
}