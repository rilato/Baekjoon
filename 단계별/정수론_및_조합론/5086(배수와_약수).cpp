#include <iostream>

using namespace std;

int main()
{
	while (1) {
		int num1, num2;

		cin >> num1 >> num2;

		if (num1 == 0 && num2 == 0)
			break;

		if (num2 % num1 == 0) {
			cout << "factor\n";
			continue;
		}

		if (num1 % num2 == 0) {
			cout << "multiple\n";
			continue;
		}

		cout << "neither\n";
	}
}