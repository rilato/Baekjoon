#include <iostream>

using namespace std;

int main() {
	int A, B;

	while (1) {
		cin >> A >> B;

		if (A >= 1 and A <= 10000 and B >= 1 and B <= 10000) {
			cout << A + B << endl;
			cout << A - B << endl;
			cout << A * B << endl;
			cout << A / B << endl;
			cout << A % B << endl;
			break;
		}
	}
}