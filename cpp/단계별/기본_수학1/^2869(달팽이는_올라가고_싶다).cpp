// for������ ������ �� ������, �ð��� �����ɸ��Ƿ�, ���������� �𵨸��� �� �����Ѵ�.

#include <iostream>

using namespace std;

int main() {
	int day, night, oneDay, days, height;

	cin >> day >> night >> height;

	height -= day;	// height - day��ŭ�� �����ϸ� ������ ��ħ�� day��ŭ ������ �̲������� �ʴ´�.
	days = height / (day - night) + 1;	// height - day��ŭ ���µ� �ɸ��� ��¥�� ���Ѵ�. ������ day��ŭ �������Ƿ�, �Ϸ縦 ���ϰ� �����Ѵ�.

	if (height % (day - night) == 0)	// �� ��, �������� 0�� ���� days��ŭ ������ ������ ���� day��ŭ ������ ������,
		cout << days;
	else								// �������� 0�� �ƴ� ���� ���� �����ϱ⿡ �̵��Ÿ��� ���� ���ڶ�Ƿ�, 1�� �߰��� ������� �Ѵ�.
		cout << days + 1;
}