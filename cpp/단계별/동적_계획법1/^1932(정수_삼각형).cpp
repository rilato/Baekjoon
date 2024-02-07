// https://gaeunhan.tistory.com/67

// 입력 받은 이차원 배열 자신에
// 합을 더해나가며 값을 저장한다.

#include <iostream>
#include <algorithm>

using namespace std;

// main 함수 안에 변수를 선언하지 않아,
// long long을 담을 수 없는 main 크기의 문제가 해결된다.
int N;
long long arr[500][500] = { 0, };
long long answer = 0;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	// N == 1인 경우의 문제를 해결해준다.
	if (N == 1) {
		cout << arr[0][0];
		return 0;
	}

	// 값이 입력된 자리를 현재까지의 합으로 갱신한다.
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			// 맨 왼쪽의 경우, 윗 부분에서 max를 고를 필요가 없다.
			// 경우의 수가 하나 뿐이기 때문.
			if (j == 0)
				arr[i][j] = arr[i - 1][j] + arr[i][j];
			// 맨 오른쪽의 경우, 윗 부분에서 max를 고를 필요가 없다.
			// 경우의 수가 하나 뿐이기 때문.
			else if (j == i)
				arr[i][j] = arr[i - 1][j - 1] + arr[i][j];
			// 가운데에 있는 수는, 윗 부분에서 큰 값(현재까지 더한 값 중 큰 값)을 택해
			// 더하여 저장한다.
			else
				arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];

			// 현재까지 입력한 값 중, 가장 큰 값을 answer에 넣는다.
			// 실시간으로 합의 최대를 구해 갱신하는 것이다.
			answer = max(answer, arr[i][j]);
		}
	}

	cout << answer;
}