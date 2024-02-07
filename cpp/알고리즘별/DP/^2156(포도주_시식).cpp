#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v;
vector <vector <int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N);
	dp.resize(N, vector <int>(3));

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 0 : 안마심 / 1 : 처음으로 마심 / 2 : 두 번 연속 마심
	dp[0][0] = 0;
	dp[0][1] = v[0];
	dp[0][2] = 0;

	for (int i = 1; i < N; i++) {
		// 안마신다는 것은, 이전에 안마셨거나, 한 번 마셨거나, 두 번 연속 마셨을 경우임
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		// 처음으로 마신다는 것은, 이전에 안마신 경우 + 지금 잔을 마시는 경우임
		dp[i][1] = dp[i - 1][0] + v[i];
		// 두 번 연속 마신다는 것은, 이전에 한 잔 마신 경우 + 지금 잔을 마시는 경우임
		dp[i][2] = dp[i - 1][1] + v[i];
	}

	cout << max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2]));

	return 0;
}