// min (dp[i - 1] + 1, dp[i / 2] + 1, dp[i / 3] + 1)
// 위에 것을 연산하기 위해, 조건 별로 나누어 해결한다.

// 위의 식을 for문 내에서 바로 쓸 수 없는 이유는
// 어떤 수가 2나 3으로 나누어 떨어지지 않음에도 불구하고,
// 단지 최소 값을 도출한다는 이유로 min 값을 결정할 수 있기 때문이다.

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