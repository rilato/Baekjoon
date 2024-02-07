#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b, c;

	cin >> a >> b >> c;

	if (2 * c <= a + b)
		cout << (a + b) - 2 * c;
	else
		cout << a + b;
}