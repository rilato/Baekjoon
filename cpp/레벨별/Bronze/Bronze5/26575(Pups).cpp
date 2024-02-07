#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		double d, f, p; cin >> d >> f >> p;

		double cost = d * f * p;

		cout << fixed;
		cout.precision(2);
		cout << "$" << cost << "\n";
	}

	return 0;
}