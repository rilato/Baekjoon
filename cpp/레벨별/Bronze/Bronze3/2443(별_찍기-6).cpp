#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M = 0;

	cin >> N;

	for (int i = N; i > 0; i--) {

		int num = i * 2 - 1;

		for (int j = 0; j <= M - 1; j++) {
			cout << ' ';
		}

		for (int j = 1; j <= num; j++) {
			cout << '*';
		}

		cout << '\n';

		M++;
	}
}