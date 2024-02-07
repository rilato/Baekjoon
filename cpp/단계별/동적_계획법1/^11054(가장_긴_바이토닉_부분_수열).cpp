// 11053 ����
// https://yabmoons.tistory.com/143

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int sum = 0;
	int reverse_sum = 0;
	int arr[1000] = { 0, };
	int dp[1000] = { 0, };
	int reverse_dp[1000] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// �տ������� ����ؼ� �����ϴ� �κм��� ���
	for (int i = 0; i < N; i++) {
		// �⺻ ���̰� 1�̹Ƿ� dp�� 1�� �ʱ�ȭ
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			// ���� ���캸�� ����, ���� ������ ���Ͽ� ���� ����Ű�� ���� �� ū ���
			// max�� ����
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// �ڿ������� ����ؼ� �����ϴ� �κм��� ���
	for (int i = N - 1; i >= 0; i--) {
		reverse_dp[i] = 1;

		for (int j = N - 1; j >= i; j--) {
			if (arr[i] > arr[j]) {
				reverse_dp[i] = max(reverse_dp[i], reverse_dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		sum = max(sum, dp[i] + reverse_dp[i]);
	}

	// �ε��� i��°�� �ִ� ���� �ڱ� �ڽ��� �� �� ī�����ϹǷ�, 1�� ����.
	cout << sum - 1;
}