#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double num, temp;

	cin >> temp;

	while (1) {
		cin >> num;

		if (num == 999)
			break;

		cout << fixed;
		cout.precision(2);

		cout << num - temp << '\n';

		temp = num;
	}
}