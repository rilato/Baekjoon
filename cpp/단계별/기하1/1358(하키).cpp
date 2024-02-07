#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// x - radius ~ x + width + radius, y ~ y + height ���̿� �ִ� �� �߿���
	// Ư���� �� (x1, y1)���� x1�� x���� �۰ų� x1�� x + width���� ū ���� ��
	// (x1, y1)�� (x, y) ������ �Ÿ��� ���������� ū ���� �ɷ�����.

	int W, H, X, Y, P;
	int radius, x, y;
	double r;
	int count = 0;

	cin >> W >> H >> X >> Y >> P;

	radius = H / 2;

	for (int i = 0; i < P; i++) {
		cin >> x >> y;

		// Ʈ���� ��� ������ �� �ִ� ū ���簢�� ���ο���, ���ǿ� �����ϴ� �͸� count�Ѵ�.
		if (X - radius <= x && x <= X + W + radius && Y <= y && y <= Y + H) {
			if (x < X) {
				r = sqrt((x - X) * (x - X) + (Y + radius - y) * (Y + radius - y));

				if (r <= radius)
					++count;
			}
			else if (x > X + W) {
				r = sqrt((X + W - x) * (X + W - x) + (Y + radius - y) * (Y + radius - y));

				if (r <= radius)
					++count;
			}
			else
				++count;
		}
	}

	cout << count;
}