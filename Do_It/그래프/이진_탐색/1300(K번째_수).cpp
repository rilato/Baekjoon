// 이진 탐색으로 중앙값보다 작은 수의 개수를 세면서 범위를 절반씩 줄이는 방법으로 B[k]를 구한다.
// 즉, 작은 수의 개수가 k - 1개인 중앙값이 정답이다.

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

long long findNum(int left, int right);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	// 값을 입력 받는 순간, 10^5 * 10^5 => 시간초과
	//for (long long i = 0; i < N; i++) {
	//	for (long long j = 0; j < N; j++) {
	//		A[i * (N - 1) + j] = i * j;
	//	}
	//}

	cout << findNum(1, K);

	return 0;
}

long long findNum(int left, int right) {
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long cnt = 0;

		// 중앙값보다 작은 수는 몇 개인지 계산
		for (int i = 1; i <= N; i++) {
			// B[K]보다 작은 수를 카운트하는 핵심 로직
			cnt += min(mid / i, N);
		}

		if (cnt < K) {
			left = mid + 1;
		}
		else {
			// 현재 단계의 중앙 값을 ans에 저장
			ans = mid;
			right = mid - 1;
		}
	}

	return ans;
}