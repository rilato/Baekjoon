#include <iostream>

using namespace std;

int hansoo(int num);

int main()
{
	int ans, input;
	int arr[1001] = { 0, };	// 9999�� ��� 9999 + 9 + 9 + 9 + 9 �ؼ� 10000�� �Ѿ�Ƿ�, 10000���� ū �迭�� �������� ��
	int count = 0;

	cin >> input;

	for (int i = 1; i <= input; i++) {
		ans = hansoo(i);
		++arr[ans];
	}

	for (int i = 1; i <= input; i++) {
		if (arr[i] != 0)
			++count;
	}

	cout << count;
}

int hansoo(int num)
{
	int one, ten, hundred;

	if (num <= 99)
		return num;
	else if (num == 1000)
		return 0;
	else {
		hundred = num / 100;
		ten = (num / 10) % 10;
		one = num % 10;

		if (hundred - ten == ten - one)
			return num;

		return 0;
	}
}


// �迭�� ������� ���� �ٸ� Ǯ��

#include <iostream>

using namespace std;

bool hansoo(int a) {
	if (a < 100)
		return true;

	int a1, a2, a3;

	a3 = a / 100;
	a1 = a % 10;
	a2 = a % 100 / 10;

	if (a3 - a2 == a2 - a1)
		return true;

	return false;
}

int main(void) {
	int N, count = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (hansoo(i))
			count++;
	}

	cout << count;
}