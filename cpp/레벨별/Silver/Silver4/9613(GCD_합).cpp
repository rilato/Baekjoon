#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;

	cin >> T;

	while (T--) {
		long long sum = 0;

		cin >> N;

		vector <int> v(N);

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				sum += GCD(v[i], v[j]);
			}
		}

		cout << sum << '\n';
	}
}

int GCD(int a, int b) {
	int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}