// 블루레이의 최소 값은 입력받은 값들 중 가장 큰 값이다.
// 블루레이의 최대 값은 입력받은 모든 값들의 합이다.
// 따라서 정렬을 따로 진행하지 않아도 된다. (left = maximum, right = sum이고, 그 사이 값(연속적인 자연수)들을 조사하므로)
// 그 사이의 값들 중, 가장 알맞은 값을 찾는 것이 관건이다.

// 일반적인 이진 탐색과 다르게, 특정 값과 A[mid]가 같다는 조건이 없다.
// 문제에서 주어진 찾는 값이 없고, 최적의 값이 나올 때 까지 탐색을 계속 진행하기 때문이다.

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int maximum = 0;
int sum = 0;
vector <int> A;

int findNum(int left, int right);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];

		if (maximum < A[i])
			maximum = A[i];

		sum += A[i];
	}

	// 중앙 값의 크기로 모든 레슨을 저장할 수 있으면 종료 인덱스 = 중앙값 - 1
	// 중앙 값의 크기로 모든 레슨을 저장할 수 없으면 시작 인덱스 = 중앙값 + 1

	int ans = findNum(maximum, sum);

	cout << ans;

	return 0;
}

int findNum(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;	// 중간 인덱스
		int cnt = 0;	// 현재 사용한 블루레이의 개수
		int sum = 0;	// 레슨의 합

		for (int i = 0; i < N; i++) {
			// 이전까지 레슨의 합에, 현재 레슨 값을 더한 것이 현재 탐색 중인 블루레이의 사이즈를 넘어선다면,
			if (sum + A[i] > mid) {
				cnt++;		// 블루레이 개수를 한 개 추가
				sum = 0;	// 레슨의 합을 0으로 초기화
			}

			sum += A[i];	// 레슨의 합에 다시 현재 값을 넣기
		}

		// for문을 통해 총 블루레이의 개수 (cnt)가 나왔을 것.
		// sum이 있다면, 마지막 블루레이의 개수가 계산되지 않은 것이므로, cnt에 1을 추가.
		if (sum != 0) {
			cnt++;
		}
		// count된 블루레이의 개수가 주어진 M보다 크다면, count 개수를 줄여야하므로, 블루레이의 사이즈를 늘리기 위해 left = mid + 1;
		if (cnt > M) {
			left = mid + 1;
		}
		// count된 블루레이의 개수가 주어진 M보다 작다면, count 개수를 늘려야하므로, 블루레이의 사이즈를 줄이기 위해 right = mid - 1;
		else {
			right = mid - 1;
		}
	}

	return left;
}