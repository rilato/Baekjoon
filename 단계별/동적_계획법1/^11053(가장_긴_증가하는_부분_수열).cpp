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
		// 기본 길이가 1이므로 dp는 1로 초기화
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			// 현재 살펴보는 값과, 이전 값들을 비교하여 현재 가리키는 값이 더 큰 경우
			// max를 갱신
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		// 현재까지 max 중 가장 큰 값을 sum에 저장
		sum = max(sum, dp[i]);
	}

	cout << sum;
}