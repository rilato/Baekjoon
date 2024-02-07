// R, C, N이 1,000,000 이하의 범위이지만, 둘을 곱했을 때의 결과가 int의 범위를 넘어가므로 long long을 쓰도록 한다.

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long R, C, N;
	long long r, c;

	cin >> R >> C >> N;

	r = R / N;
	c = C / N;

	if (R % N) {
		r++;
	}
	if (C % N) {
		c++;
	}

	cout << r * c;

	return 0;
}