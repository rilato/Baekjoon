#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;

	cin >> N;

	while (1) {
		cin >> num;

		if (!num)
			break;

		if (num % N)
			cout << num << " is NOT a multiple of " << N << ".\n";
		else
			cout << num << " is a multiple of " << N << ".\n";
	}
}