// 1���� ���� ����� ���� ��� ���ܰ� �߻��� �� �����Ƿ� ����ؾ� �Ѵ�.

#include <iostream>

using namespace std;

int main() {
	int input, width, height, order, floor, roomNumber;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> height >> width >> order;

		if (order % height != 0) {
			roomNumber = order / height + 1; // �� ��° ������
			floor = order % height;		// �� ������
		}

		else {			        // �� �� == N��° �մ�
			roomNumber = order / height;
			floor = height;
		}

		cout << floor * 100 + roomNumber << '\n';
	}
}