#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	unsigned int sum = 0;

	while (1) {
		cin >> n;

		if (n == -1)
			break;

		sum += n;
	}

	cout << sum;

	return 0;
}