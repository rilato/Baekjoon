// 아이패드 필기 참고
// https://yabmoons.tistory.com/18

// 2579 계단오르기와 유사

// 점화식 : dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i], dp[i - 1])

#include <iostream>
#include <algorithm>

using namespace std;

int maxNum(int A, int B);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int arr[10001] = { 0, };
	long long temp;
	long long dp[10001] = { 0, };

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = maxNum(arr[1] + arr[2], maxNum(arr[1] + arr[3], arr[2] + arr[3]));

	for (int i = 4; i <= N; i++) {
		dp[i] = maxNum(dp[i - 3] + arr[i - 1] + arr[i], maxNum(dp[i - 2] + arr[i], dp[i - 1]));
	}

	cout << dp[N];
}

int maxNum(int A, int B) {
	if (A > B)
		return A;
	else
		return B;
}