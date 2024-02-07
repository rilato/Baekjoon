#include <iostream>

using namespace std;

int main()
{
	int input;
	int remain;
	int arr[42] = { 0, };

	for (int i = 0; i < 10; i++) {
		cin >> input;

		remain = input % 42;

		++arr[remain];
	}

	int count = 0;

	for (int i = 0; i < 42; i++) {
		if (arr[i] != 0)
			++count;
	}

	cout << count;
}