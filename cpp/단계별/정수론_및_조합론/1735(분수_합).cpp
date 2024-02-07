#include <iostream>

using namespace std;

int GCD(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d;
	int bunza, bunmo;

	cin >> a >> b >> c >> d;

	bunmo = b * d;
	bunza = a * d + b * c;

	int gcd = GCD(bunza, bunmo);

	if (gcd == 1) {
		cout << bunza << " " << bunmo;
	}
	else {
		cout << bunza / gcd << " " << bunmo / gcd;
	}
}

int GCD(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}