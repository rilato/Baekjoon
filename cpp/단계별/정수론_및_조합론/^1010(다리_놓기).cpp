// mCn으로 해결한다.

// 틀린 코드
// combination 함수의 while문에서 numerator와 denominator가 long long의 범위를 벗어날 수 있다.

#include <iostream>

using namespace std;

void combination(int N, int M);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, N, M;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> N >> M;
		combination(N, M);
	}
}

void combination(int N, int M) {
	long long numerator = 1;
	long long denominator = 1;
	int count = 0;
	int breakPoint = N;

	while (1) {
		if (count == breakPoint)
			break;

		++count;

		numerator *= M--;
		denominator *= N--;
	}

	cout << numerator / denominator << ' ';
}


// 맞은 코드

// 파스칼의 삼각형과 이차원 배열을 이용한다.

#include <iostream>

using namespace std;

void combination(int N, int M);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, N, M;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> N >> M;
		combination(N, M);
	}
}

void combination(int N, int M) {
	int arr[31][31] = { 0, };

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	cout << arr[M][N] << '\n';
}