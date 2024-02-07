//(x, y) 중심을 기준으로 반지름이 R인 원을 그려보아 겹치는 점의 개수를 센다.
//두 중심 사이의 거리 (distance)와 반지름 사이의 거리 (r, R)을 따져본다.

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

		// 무조건 r1이 큰 원으로 변경
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

		distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));	// 두 점 사이의 거리

		R = (double)r1 + r2;
		r = (double)r1 - r2;

		// 동심원
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}

		// 내부의 원인데, 한쪽 꼭짓점이 붙은 경우
		else if (distance == r) {
			cout << 1 << '\n';
		}

		// 내부의 원인데, 겹치는 부분이 없는 경우.
		else if (distance < r) {
			cout << 0 << '\n';
		}

		// 외부의 원 ( distance > r )
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