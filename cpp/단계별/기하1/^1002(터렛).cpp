//(x, y) �߽��� �������� �������� R�� ���� �׷����� ��ġ�� ���� ������ ����.
//�� �߽� ������ �Ÿ� (distance)�� ������ ������ �Ÿ� (r, R)�� ��������.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int input;
	int x1, y1, r1, x2, y2, r2, r;
	double distance, R;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// ������ r1�� ū ������ ����
		if (r2 > r1) {
			int temp;

			temp = x1;
			x1 = x2;
			x2 = temp;

			temp = y1;
			y1 = y2;
			y2 = temp;

			temp = r1;
			r1 = r2;
			r2 = temp;
		}

		distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));	// �� �� ������ �Ÿ�

		R = (double)r1 + r2;
		r = (double)r1 - r2;

		// ���ɿ�
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}

		// ������ ���ε�, ���� �������� ���� ���
		else if (distance == r) {
			cout << 1 << '\n';
		}

		// ������ ���ε�, ��ġ�� �κ��� ���� ���.
		else if (distance < r) {
			cout << 0 << '\n';
		}

		// �ܺ��� �� ( distance > r )
		else {
			if (distance == R)
				cout << 1 << '\n';
			else if (distance < R)
				cout << 2 << '\n';
			if (distance > R)
				cout << 0 << '\n';
		}
	}
}