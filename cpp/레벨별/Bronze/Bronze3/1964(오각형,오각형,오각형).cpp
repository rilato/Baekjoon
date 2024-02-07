#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, sum = 5;

	cin >> N;

	if (N == 1) cout << sum;

	else {
		for (int i = 2; i <= N; i++) {
			sum += 3 * i + 1;
		}
		cout << sum % 45678;
	}
}