#include <iostream>

using namespace std;

int main() {
	int A, B;

	while (1) {
		cin >> A >> B;

		if (A > 0 and A < 10 and B > 0 and B < 10) {
			cout << A + B;
			break;
		}
	}
}