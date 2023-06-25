#include <iostream>

using namespace std;

int fibonacci(int num);

int main() {
	int num;

	cin >> num;

	cout << fibonacci(num);
}

int fibonacci(int num) {
	if (num == 0)
		return 0;

	if (num == 1)
		return 1;

	return fibonacci(num - 1) + fibonacci(num - 2);
}