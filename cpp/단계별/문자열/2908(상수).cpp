#include <iostream>
#include <string>

using namespace std;

int changeNum(int num);

int main()
{
	int num1, num2;
	int changeNum1, changeNum2;

	cin >> num1 >> num2;

	changeNum1 = changeNum(num1);
	changeNum2 = changeNum(num2);

	if (changeNum1 > changeNum2)
		cout << changeNum1;
	else
		cout << changeNum2;
}

int changeNum(int num)
{
	int hundred, ten, one;

	hundred = num / 100;
	ten = (num / 10) % 10;
	one = num % 10;

	num = hundred + ten * 10 + one * 100;

	return num;
}