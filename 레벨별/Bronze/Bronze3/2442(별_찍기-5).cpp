#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;

	M = N;

	for (int i = 1; i <= N; i++) {
		M = N - i;

		for (int j = M; j > 0; j--) {
			cout << ' ';
		}

		int num = i * 2 - 1;

		for (int j = 1; j <= num; j++) {
			cout << '*';
		}

		cout << '\n';
	}
}