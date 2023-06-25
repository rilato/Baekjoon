// https://guiyum.tistory.com/16
// https://snnchallenge.tistory.com/67
// 아이패드에 필기 참고

// 이전 단계 까지의 합과, 현재의 값을 기준으로 생각한다.

#include <iostream>
#include <algorithm>

using namespace std;

int N[100000];
int dp[100000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> N[i];

	dp[0] = N[0];

	int result = dp[0];

	for (int i = 1; i < n; i++) {
		// dp 에는 연속 합과 현재 값 중 큰 값을 선택하여 넣는다.
		dp[i] = max(dp[i - 1] + N[i], N[i]);

		// result에는 현재까지의 연속 합 중 가장 큰 결과 값을 저장한다.
		result = max(result, dp[i]);
	}

	cout << result << endl;
}