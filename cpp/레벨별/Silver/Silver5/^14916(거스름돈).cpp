#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cost;

	cin >> cost;

	int five = cost / 5;

	if (cost % 5 == 0) {
		cout << five;
		return 0;
	}

	while (five >= 0) {
		int result = (cost - (five * 5)) % 2;

		int two = (cost - (five * 5)) / 2;

		if (result == 0) {
			cout << five + two;
			return 0;
		}

		five--;
	}

	cout << -1;
}