// k ���� n ȣ�� k - 1 ���� 1ȣ���� n ȣ���� ��� ����� ���� ���� ���ε�
// �̴� k - 1 ���� n ȣ�� k ���� n - 1 ȣ�� �հ� ����.
// �ֳ��ϸ� k ���� n - 1 ȣ�� k - 1 ���� 1ȣ���� n - 1 ȣ������ ���̱� �����̴�.

#include <iostream>

using namespace std;

int getNum(int f, int n);

int main() {
	int floor, roomNumber, input;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> floor >> roomNumber;
		cout << getNum(floor, roomNumber) << '\n';
	}

}

int getNum(int f, int n) {
	if (n == 1)
		return 1;
	if (f == 0)
		return n;
	return (getNum(f - 1, n) + getNum(f, n - 1));
}