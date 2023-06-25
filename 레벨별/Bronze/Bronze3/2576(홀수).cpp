#include <iostream>

using namespace std;

bool checkOddNum(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	int sum = 0;
	int min = 100;

	for (int i = 0; i < 7; i++) {
		cin >> num;

		if (checkOddNum(num)) {
			sum += num;

			if (num <= min)
				min = num;
		}
	}

	if (!sum)
		cout << -1;
	else
		cout << sum << '\n' << min;
}

bool checkOddNum(int num) {
	if (num % 2)
		return true;

	return false;
}