// 유클리드 호제법을 이용하여 해결한다.

#include <iostream>

using namespace std;

int GCD(int num1, int num2);
void LCM(int num1, int num2, int gcd);

int main() {
	int input, num1, num2, gcd;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num1 >> num2;
		gcd = GCD(num1, num2);
		LCM(num1, num2, gcd);
	}
}

int GCD(int num1, int num2) {
	int r;

	while (num2 != 0) {
		r = num1 % num2;
		num1 = num2;
		num2 = r;
	}

	return num1;
}

void LCM(int num1, int num2, int gcd) {
	num1 /= gcd;
	num2 /= gcd;

	cout << num1 * num2 * gcd << '\n';
}