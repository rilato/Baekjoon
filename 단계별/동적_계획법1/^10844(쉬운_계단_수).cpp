// 틀린 풀이
// 점화식 : dp[i] = dp[i - 1] * 2 - (i - 1);

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long dp[101] = { 0, };

	cin >> N;

	dp[1] = 9;

	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] * 2 - (i - 1)) % 1000000000;
	}

	cout << dp[N] % 1000000000;
}


// 맞은 풀이
// https://yabmoons.tistory.com/22
// 점화식 : dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long dp[101][10] = { 0, };
	long long sum = 0;

	cin >> N;

	dp[1][0] = 0;

	for (int j = 1; j <= 9; j++)
		dp[1][j] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int j = 0; j <= 9; j++) {
		sum += dp[N][j];
	}

	cout << sum % 1000000000;
}