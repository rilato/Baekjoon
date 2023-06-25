#include <iostream>

using namespace std;

int T, num;
long long arr[46];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i < 46; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cin >> T;

	while (T--) {
		cin >> num;
		cout << arr[num] << '\n';
	}

	return 0;
}