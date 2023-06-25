#include <iostream>

using namespace std;

int N, a, b;
int minX = 10001, minY = 10001;
int maxX = -10001, maxY = -10001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		if (a <= minX)
			minX = a;
		if (a >= maxX)
			maxX = a;
		if (b <= minY)
			minY = b;
		if (b >= maxY)
			maxY = b;
	}

	if (N == 1) {
		cout << 0;
		return 0;
	}
	else {
		cout << (maxX - minX) * (maxY - minY);
	}

	return 0;
}