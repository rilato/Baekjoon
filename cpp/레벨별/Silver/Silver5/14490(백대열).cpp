#include <iostream>

using namespace std;

int gcd(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, GCD;
	char c;

	cin >> n >> c >> m;

	GCD = gcd(n, m);

	cout << n / GCD << ":" << m / GCD;
}

int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}