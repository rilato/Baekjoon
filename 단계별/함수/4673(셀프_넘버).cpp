#include <iostream>
#include <string>

using namespace std;

int selfNumber(int num);

int main()
{
	int ans;
	int arr[10100] = { 0, };	// 9999�� ��� 9999 + 9 + 9 + 9 + 9 �ؼ� 10000�� �Ѿ�Ƿ�, 10000���� ū �迭�� �������� ��

	for (int i = 1; i <= 10000; i++) {
		ans = selfNumber(i);
		++arr[ans];
	}

	for (int i = 1; i <= 10000; i++) {	// 10000������ ����ؾ��ϹǷ� 10000�� �������� ��
		if (arr[i] == 0)
			cout << i << '\n';
	}
}

int selfNumber(int num)	// self number�� Ȯ��
{
	string changeNum;
	string character;
	int sum = 0;

	changeNum = to_string(num);

	for (int i = 0; i < changeNum.size(); i++) {
		character = changeNum.substr(i, 1);
		sum += stoi(character);
	}

	sum += num;

	return sum;
}



// ���ڷ� �ٲ��� �ʰ� ���ڷ� �ذ��ϱ� ���ؼ��� �Ʒ��� ���� �ۼ��� ���� �ִ�.
// int selfNumber(int i) {
//	int res = i;
//	if (i >= 10000) { res += i / 10000; i %= 10000; }
//	if (i >= 1000) { res += i / 1000; i %= 1000; }
//	if (i >= 100) { res += i / 100; i %= 100; }
//	if (i >= 10) { res += i / 10; i %= 10; }
//	return res += i;
//}