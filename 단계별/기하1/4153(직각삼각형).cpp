#include <iostream>

using namespace std;

int main() {
	int num1, num2, num3;

	while (1) {
		cin >> num1 >> num2 >> num3;

		if (!num1 && !num2 && !num3)
			break;

		if (num1 * num1 == num2 * num2 + num3 * num3 || \	// \�� �ڵ��� ���̰� �� ��, ���� �ٿ� �̾�� ����
			num2 * num2 == num1 * num1 + num3 * num3 || \
			num3 * num3 == num1 * num1 + num2 * num2)
			cout << "right" << '\n';

		else
			cout << "wrong" << '\n';
	}
}