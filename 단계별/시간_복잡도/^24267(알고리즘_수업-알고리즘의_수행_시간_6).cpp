#include <iostream>

using namespace std;

long long N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cout << (N * (N - 1) * (N - 2)) / 6 << '\n' << 3;

	return 0;
}