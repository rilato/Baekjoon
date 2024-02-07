#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;

	M = N;

	while (N) {
		for (int i = 0; i < M - N; i++) {
			cout << ' ';
		}

		for (int i = N; i > 0; i--) {
			cout << '*';
		}

		cout << '\n';

		N--;
	}
}