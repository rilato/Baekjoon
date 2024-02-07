#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int num;

	while (1) {
		int cm = 0;

		cin >> N;

		if (N == 0)
			break;

		while (N) {
			num = N % 10;

			if (num == 1)
				cm += 3;

			else if (num == 0)
				cm += 5;

			else
				cm += 4;

			N /= 10;
		}

		cout << cm + 1 << '\n';
	}
}