// https://nanyoungkim.tistory.com/182

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int dp[101][100001] = { 0, };
int W[101] = { 0, };
int V[101] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	// N개의 물건에 대해 살펴본다.
	for (int i = 1; i <= N; i++) {
		// 각 물건의 무게에 대해 살펴본다.
		for (int limit = 1; limit <= K; limit++) {
			// 1. 물건을 담을 수 없을 경우
			if (W[i] > limit)
				dp[i][limit] = dp[i - 1][limit];
			// 2. 물건을 담을 수 있는 경우
			else
				dp[i][limit] = max(dp[i - 1][limit - W[i]] + V[i], dp[i - 1][limit]);
		}
	}

	cout << dp[N][K];
}