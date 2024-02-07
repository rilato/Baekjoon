#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, temp = 0;
	cin >> num;
	int ball = 1;

	for (int i = 0; i < num; i++) {
		int a, b;

		cin >> a >> b;

		if (ball == a) {
			ball = b;
			continue;
		}

		if (ball == b)
			ball = a;
	}

	cout << ball;
}