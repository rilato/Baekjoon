// 도화지에 색종이가 붙는 부분을 true로 만들고, 그것의 개수를 세도록 한다.

#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool arr[100][100] = { 0, };
	int T, a, b;
	int cnt = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> b;

		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				if (!arr[j][k]) {
					arr[j][k] = 1;
					cnt++;
				}
			}
		}
	}

	cout << cnt;
}