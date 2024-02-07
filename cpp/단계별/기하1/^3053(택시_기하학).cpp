#include <iostream>
#define PI 3.1415926535897932384626

using namespace std;

int main() {
	double radius;

	cin >> radius;

	cout.precision(6);		// fixed 없이 사용하면 그냥 6개의 '유효숫자만' 표기
	cout << fixed << PI * radius * radius << '\n' << 2 * radius * radius;	// fixed는 소수점 아래 자리수 고정을 위해 사용.
}