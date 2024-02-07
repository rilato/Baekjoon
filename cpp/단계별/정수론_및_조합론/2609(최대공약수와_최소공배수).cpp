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

// ��Ŭ���� ȣ������ �̿��� �ִ�����
int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

// 24 18 �̶�� �ϸ�, �ִ������� 6�̹Ƿ� 24 / 6 = 4, 18 / 6 = 3�̰�
// �ּҰ������ 4 * 3 * 6�� �ȴ�.
int lcm(int a, int b, int c) {
	// a�� �ִ������� ���� ���� a�� �����Ѵ�.
	a /= c;
	b /= c;

	return c * a * b;
}