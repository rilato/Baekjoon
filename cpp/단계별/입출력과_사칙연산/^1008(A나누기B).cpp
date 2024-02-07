//cin으로 a, b 변수를 받고 cout으로 a*b를 출력한다.
//상대오차가 10⁻⁹ 이내여야 한다는 단서가 있으므로 소수점 아래 11자리에서 반올림하여 10자리까지 표현할 수 있도록 cout.precision(10)을 선언한 후 출력한다.

#include <iostream>

using namespace std;

int main() {
	double A, B;

	while (1) {
		cin >> A >> B;

		if (A > 0 && A < 10 && B > 0 && B < 10) {
			cout.precision(10);
			cout << A / B;
			break;
		}
	}
}