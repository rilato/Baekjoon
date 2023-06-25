// 점화식을 구하여 문제를 해결한다.

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		int dp[12] = { 0, };

		dp[1] = 1;	// 1
		dp[2] = 2;	// 1 + 1, 2
		dp[3] = 4;	// 1 + 1 + 1, 1 + 2, 2 + 1, 3

		for (int i = 4; i < 12; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}