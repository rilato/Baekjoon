// 윤년은 4의 배수이면서 100의 배수가 아닐때, 혹은 400의 배수일 때

#include <iostream>

using namespace std;

int main()
{
	int year;

	cin >> year;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		cout << 1;
	else
		cout << 0;
}