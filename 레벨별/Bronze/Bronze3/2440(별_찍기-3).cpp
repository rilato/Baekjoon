#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	while (N) {
		for (int i = N; i > 0; i--) {
			cout << '*';
		}

		cout << '\n';

		N--;
	}
}