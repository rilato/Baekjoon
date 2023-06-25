#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// x - radius ~ x + width + radius, y ~ y + height 사이에 있는 것 중에서
	// 특정한 점 (x1, y1)에서 x1이 x보다 작거나 x1이 x + width보다 큰 점들 중
	// (x1, y1)과 (x, y) 사이의 거리가 반지름보다 큰 것을 걸러낸다.

	int W, H, X, Y, P;
	int radius, x, y;
	double r;
	int count = 0;

	cin >> W >> H >> X >> Y >> P;

	radius = H / 2;

	for (int i = 0; i < P; i++) {
		cin >> x >> y;

		// 트랙을 모두 포함할 수 있는 큰 직사각형 내부에서, 조건에 만족하는 것만 count한다.
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