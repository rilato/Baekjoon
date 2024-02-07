#include <iostream>

using namespace std;

int main() {
	int a, b, c;

	while (1) {
		cin >> a >> b >> c;

		if (!a && !b && !c)
			break;

		if (c - b == b - a)
			cout << "AP " << c + c - b << '\n';
		else
			cout << "GP " << c * c / b << '\n';
	}
}