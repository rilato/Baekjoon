#include <iostream>

using namespace std;

int main() {
	int num1, num2, num3;

	cin >> num1 >> num2 >> num3;

	if (num1 == num2 && num2 == num3)	// 두 개씩 끊어서 &&로 묶어야 한다. num1 == num2 == num3는 인식하지 못한다.
		cout << 10000 + num1 * 1000;

	else if (num1 == num2)
		cout << 1000 + num1 * 100;

	else if (num2 == num3)
		cout << 1000 + num2 * 100;

	else if (num1 == num3)
		cout << 1000 + num1 * 100;

	else {
		int max = 0;

		if (num1 > max)
			max = num1;

		if (num2 > max)
			max = num2;

		if (num3 > max)
			max = num3;

		cout << max * 100;
	}
}