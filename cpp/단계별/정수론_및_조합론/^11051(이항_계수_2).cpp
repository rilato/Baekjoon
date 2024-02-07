// 파스칼의 삼각형에서 윗줄의 두 수의 합이 아랫줄의 수임을 이용해 계산한다.

// ios::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);를 사용해
// C와의 연결을 끊으면, 실행이 되지 않는다.

#include <iostream>

using namespace std;

int arr[1001][1001] = { 0, };

int main() {
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
		}
	}

	cout << arr[N][K];
}