#include <iostream>

using namespace std;

int main()
{
	int arr[9];
	int input;
	int count = 1;

	int min = 100;
	int max = 1;

	for (int i = 0; i < 9; i++) {
		cin >> input;

		arr[i] = input;

		if (arr[i] > max)
			max = arr[i];
	}

	int i = 0;

	while (1) {
		if (max == arr[i])
			break;

		++count;
		++i;
	}

	cout << max << endl << count;
}