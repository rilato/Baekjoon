// min (dp[i - 1] + 1, dp[i / 2] + 1, dp[i / 3] + 1)
// ���� ���� �����ϱ� ����, ���� ���� ������ �ذ��Ѵ�.

// ���� ���� for�� ������ �ٷ� �� �� ���� ������
// � ���� 2�� 3���� ������ �������� �������� �ұ��ϰ�,
// ���� �ּ� ���� �����Ѵٴ� ������ min ���� ������ �� �ֱ� �����̴�.

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;

		if (!(i % 3))
			dp[i] = min(dp[i / 3] + 1, dp[i]);

		if (!(i % 2))
			dp[i] = min(dp[i / 2] + 1, dp[i]);
	}

	cout << dp[N];
}