// https://yabmoons.tistory.com/605
// 11052와 유사한 문제.

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int card[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = card[i];

		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[N];

	return 0;
}
