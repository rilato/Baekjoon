#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d;

	for (int i = 0; i < 3; i++) {
		int count = 0;

		cin >> a >> b >> c >> d;

		if (a == 1)
			++count;
		if (b == 1)
			++count;
		if (c == 1)
			++count;
		if (d == 1)
			++count;

		if (count == 0)
			cout << "D";
		if (count == 1)
			cout << "C";
		if (count == 2)
			cout << "B";
		if (count == 3)
			cout << "A";
		if (count == 4)
			cout << "E";

		cout << '\n';
	}
}