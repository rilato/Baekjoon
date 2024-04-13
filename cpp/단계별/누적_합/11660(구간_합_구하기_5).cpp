// 자세한 설명은 다음을 참고한다.
// https://cocoon1787.tistory.com/377

#include <iostream>

using namespace std;

int arr[1025][1025] = { 0, };
int N, M, num;
int sum = 0;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int x1, y1, x2, y2;

	cin >> N >> M;

	// 계산 상의 편의를 위해 arr의 0번째 행과 0번째 열은 비워둔다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;

			if (i == 1 && j == 1)
				arr[i][j] = num;
			else if (i == 1)
				arr[i][j] = arr[i][j - 1] + num;
			else if (j == 1)
				arr[i][j] = arr[i - 1][j] + num;
			else
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + num;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << '\n';
	}
}
