#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	long long n;
	long long sum = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;

		sum += n;
	}

	cout << sum;
}