// https://hagisilecoding.tistory.com/115

#include <iostream>

using namespace std;

int T, M, N, x, y;

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> M >> N >> x >> y;

		int maxi = lcm(M, N); // 멸망 해 구하기
		int result = -1;

		// x값에 M만큼 더해가기
		for (int i = x; i <= maxi; i += M) {
			int ny = i % N; // y값

			if (ny == 0) { // 나머지가 0인 경우에는 y가 최대값 N이 됨
				ny = N;
			}

			if (ny == y) { // 정답
				result = i;
				break;
			}
		}

		cout << result << '\n';
	}

	return 0;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
