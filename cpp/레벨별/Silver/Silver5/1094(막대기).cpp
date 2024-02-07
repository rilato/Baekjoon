#include <iostream>

using namespace std;

int main() {
	int arr[7] = { 64, 32, 16, 8, 4, 2, 1 };
	int length;
	int count = 0;

	cin >> length;

	int i = 0;

	while (1) {
		if (length == 0 || i == -1)
			break;

		if (arr[i] > length)
			++i;

		else {
			++count;
			length -= arr[i--];
		}
	}

	cout << count;
}