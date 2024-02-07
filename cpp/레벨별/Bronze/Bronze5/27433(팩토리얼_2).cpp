#include <iostream>

using namespace std;

double N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cout << fixed;
	cout.precision(2);

	cout << N / 4;

	return 0;
}