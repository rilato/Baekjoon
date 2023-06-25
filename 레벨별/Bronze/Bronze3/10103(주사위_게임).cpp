#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c = 100;
	int s = 100;
	int n, a, b;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		if (a > b)
			s = s - a;
		else if (a < b)
			c = c - b;
	}

	cout << c << '\n' << s;
}