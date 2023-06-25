// N = 0일때 처리를 해준다.

#include <iostream>

using namespace std;

int factorial(int num);

int main() {
	int num;

	cin >> num;

	if (num == 0)
		cout << 1;
	else
		cout << factorial(num);
}

int factorial(int num) {
	if (num == 1)
		return 1;
	return num * factorial(num - 1);
}