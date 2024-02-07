#include <iostream>

using namespace std;

int main() {
	int num1, num2, num3;

	while (1) {
		cin >> num1 >> num2 >> num3;

		if (!num1 && !num2 && !num3)
			break;

		if (num1 * num1 == num2 * num2 + num3 * num3 || \	// \은 코드의 길이가 길 때, 다음 줄에 이어쓰기 위함
			num2 * num2 == num1 * num1 + num3 * num3 || \
			num3 * num3 == num1 * num1 + num2 * num2)
			cout << "right" << '\n';

		else
			cout << "wrong" << '\n';
	}
}