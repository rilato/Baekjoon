#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	int arr[3];

	cin >> T;

	arr[0] = T / 300;
	T %= 300;
	arr[1] = T / 60;
	T %= 60;
	arr[2] = T / 10;
	T %= 10;

	if (!T) {
		for (int i = 0; i < 3; i++)
			cout << arr[i] << ' ';
	}
	else
		cout << -1;
}