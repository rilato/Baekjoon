// ���� ������ ������ Ʋ�ȴٰ� ���� Ǯ��

#include <iostream>

using namespace std;

// ������ Ȯ���ϴ� �Լ�
bool check(int year);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int year, month, day;
	int Dyear, Dmonth, Dday;
	// ������ ������ ���� ����
	int count = 0;
	// �� ������ ���̿� 1�� �� ���� ������ ���� ��¥�� ���� ���� ����
	int years, gap;
	// �ε����� ��, ���� �� ���� �ش��ϴ� �� ��
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cin >> year >> month >> day;
	cin >> Dyear >> Dmonth >> Dday;

	if (Dyear >= year + 1000 && Dmonth >= month && Dday >= day)
		cout << "gg";
	else {
		// �Է� �⵵�� ������ ��¥ ���, �ش� ������ ���� ��¥�� ���� �ʱ�ȭ
		int after_day = days[month] - day;
		// D day�⵵�� �� ��¥ ���, �ش� ������ ���� ��¥�� ���� �ʱ�ȭ
		int before_day = Dday;

		// ���� �⵵���� ���� ��¥ ���
		for (int i = month + 1; i < 13; i++)
			after_day += days[i];

		// D-Day �⵵���� �ռ� ��¥ ���
		for (int i = 1; i < Dmonth; i++)
			before_day += days[i];

		// �� �⵵�� ���̿��� 1�� �� ���ش�.
		// �� ���� �� 1�� 365���� ��� ������ ���� ������.
		// ���� �Է³⵵�� D day �⵵�� ������ ������ Ƚ���� ����.
		// ������ ���� ������ 1�� ���Ѵ�.
		// �������� 1���� 365�Ϸ� ������, ������ 1�⿡ �Ϸ簡 �� �����Ƿ�
		// ������ ���� Ƚ���� �� 1���� ���� Ƚ���� �����ϴ�.

		// �Է� �⵵�� ���� ��¥ ó��
		if (check(year)) {
			if (month <= 2)
				after_day += 1;
		}

		// D day�⵵�� ���� ��¥ ó��
		if (check(Dyear)) {
			if (month >= 3)
				before_day += 1;
		}

		// �� �⵵ ���̿��� ������ ���� �ľ�
		for (int i = year + 1; i < Dyear; i++) {
			if (check(i))
				++count;
		}

		years = Dyear - year - 1;
		// �� �ϼ� ���
		gap = years * 365 + count + after_day + before_day;

		cout << "D-" << gap;
	}
}

// ������ Ȯ���ϴ� �Լ�
bool check(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}