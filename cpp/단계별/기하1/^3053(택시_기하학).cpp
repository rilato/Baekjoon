#include <iostream>
#define PI 3.1415926535897932384626

using namespace std;

int main() {
	double radius;

	cin >> radius;

	cout.precision(6);		// fixed ���� ����ϸ� �׳� 6���� '��ȿ���ڸ�' ǥ��
	cout << fixed << PI * radius * radius << '\n' << 2 * radius * radius;	// fixed�� �Ҽ��� �Ʒ� �ڸ��� ������ ���� ���.
}