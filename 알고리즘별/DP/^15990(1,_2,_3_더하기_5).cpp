/*
점화식은 이차원 배열로 구성이 되고,
D[n][i] 는 마지막에 오는 수가 i일 때, 1,2,3의 합으로 정수 n을 만드는 경우의 수가 된다.

D[n][1] = D[n-1][2] + D[n-1][3]
D[n][2] = D[n-2][1] + D[n-2][3]
D[n][3] = D[n-3][1] + D[n-3][2]

-> result = D[n][1] + D[n][2] + D[n][3]
*/

#include <iostream>

using namespace std;

int T, N;
// [숫자][끝자리 수]
long long dp[100001][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	// dp[n][1] = dp[n - 1][2] + dp[n - 1][3]
	// dp[n][2] = dp[n - 2][1] + dp[n - 2][3]
	// dp[n][3] = dp[n - 3][1] + dp[n - 3][2]

	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}

	while (T--) {
		cin >> N;

		cout << (dp[N][1] + dp[N][2] + dp[N][3]) % 1000000009 << '\n';
	}

	return 0;
}