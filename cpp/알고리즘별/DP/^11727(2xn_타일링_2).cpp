#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v(1001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v[1] = 1;
	v[2] = 3;

	for (int i = 3; i <= N; i++) {
		// 1. i - 1번째까지 완성된 것에 1 * 2 더하는 경우
		// 2. i - 2번째까지 완성된 것에 2 * 1 두 개 또는 2 * 2 한 개 더하는 경우
		// (참고로, 1 * 2 두 개는 위의 케이스에 포함된다. i - 1번째 벽돌이 1 * 2이고, i번째 벽돌이 1 * 2인 경우면 이 경우이기 때문)
		v[i] = (v[i - 1] + v[i - 2] * 2) % 10007;
	}

	cout << v[N] % 10007;

	return 0;
}