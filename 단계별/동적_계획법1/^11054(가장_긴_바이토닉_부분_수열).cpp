// 11053 응용
// https://yabmoons.tistory.com/143

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int sum = 0;
	int reverse_sum = 0;
	int arr[1000] = { 0, };
	int dp[1000] = { 0, };
	int reverse_dp[1000] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// 앞에서부터 출발해서 증가하는 부분수열 계산
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
	}

	// 뒤에서부터 출발해서 증가하는 부분수열 계산
	for (int i = N - 1; i >= 0; i--) {
		reverse_dp[i] = 1;

		for (int j = N - 1; j >= i; j--) {
			if (arr[i] > arr[j]) {
				reverse_dp[i] = max(reverse_dp[i], reverse_dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		sum = max(sum, dp[i] + reverse_dp[i]);
	}

	// 인덱스 i번째에 있는 수는 자기 자신을 두 번 카운팅하므로, 1을 뺀다.
	cout << sum - 1;
}