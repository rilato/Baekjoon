#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;

	cin >> A >> B;

	if (A > B)
		cout << A * (A + 1) / 2 - B * (B - 1) / 2;
	else
		cout << B * (B + 1) / 2 - A * (A - 1) / 2;
}