// 문제의 뜻을 잘 이해해본다

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x1, x2, y1, y2;
	int nn, cnt, cx, cy, cr;
	int da, db, sqrcr;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cnt = 0;

		cin >> x1 >> y1 >> x2 >> y2 >> nn;

		for (int j = 0; j < nn; j++) {
			cin >> cx >> cy >> cr;

			da = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
			db = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
			sqrcr = cr * cr;

			if (da < sqrcr && db < sqrcr)
				continue;

			else if (da < sqrcr || db < sqrcr)
				cnt++;
		}

		cout << cnt << '\n';
	}
}