// https://lesslate.github.io/onlinejudge/Baekjoon-11053%EB%B2%88/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int sum = 0;
	int arr[1000] = { 0, };
	int dp[1000] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

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

		// ������� max �� ���� ū ���� sum�� ����
		sum = max(sum, dp[i]);
	}

	cout << sum;
}