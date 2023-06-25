#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h1, h2, m1, m2, s1, s2;
	int h, m, s;
	bool check1 = 0;
	bool check2 = 0;

	for (int i = 0; i < 3; i++) {
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

		s = s2 - s1;

		// 초를 뺀 값이 음수면 60을 더해 양수로 만들어주고, 1을 내리기 위함을 표시하기 위해 check1 = 1
		if (s < 0) {
			check1 = 1;
			s += 60;
		}

		// check1이 1이라는 것은 초에서 음수가 나왔다는 것이므로 m2에서 1을 뺌
		if (check1 == 1)
			m2 -= 1;

		m = m2 - m1;

		if (m < 0) {
			check2 = 1;
			m += 60;
		}

		if (check2 == 1)
			h2 -= 1;

		h = h2 - h1;

		cout << h << ' ' << m << ' ' << s << '\n';

		check1 = 0;
		check2 = 0;
	}
}