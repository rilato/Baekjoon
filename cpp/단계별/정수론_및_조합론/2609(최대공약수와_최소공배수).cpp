#include <iostream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num1, num2, GCD, LCM;

	cin >> num1 >> num2;

	GCD = gcd(num1, num2);
	LCM = lcm(num1, num2, GCD);

	cout << GCD << '\n' << LCM;
}

// 유클리드 호제법을 이용한 최대공약수
int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

// 24 18 이라고 하면, 최대공약수는 6이므로 24 / 6 = 4, 18 / 6 = 3이고
// 최소공배수는 4 * 3 * 6이 된다.
int lcm(int a, int b, int c) {
	// a를 최대공약수로 나눈 값을 a에 저장한다.
	a /= c;
	b /= c;

	return c * a * b;
}