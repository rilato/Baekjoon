#include <iostream>
#include <vector>

using namespace std;

string S;
int K, num, dir;
vector <vector <int>> v;
int answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(5, vector <int>(8));

	for (int i = 1; i <= 4; i++) {
		cin >> S;
		
		for (int j = 0; j < S.size(); j++) {
			v[i][j] = S[j] - '0';
		}
	}

	cin >> K;

	while (K--) {
		cin >> num >> dir;

		vector <int> change;	// change에 방향 저장 (1이면 시계방향, -1이면 반시계방향, 0이면 안돌리는 것)
		change.resize(5);

		change[num] = dir;

		// 우측 탐색
		for (int i = num; i < 4; i++) {
			if (v[i][2] != v[i + 1][6]) {
				change[i + 1] = -change[i];
			}
			else {
				break;
			}
		}

		// 좌측 탐색
		for (int i = num; i > 1; i--) {
			if (v[i][6] != v[i - 1][2]) {
				change[i - 1] = -change[i];
			}
			else {
				break;
			}
		}

		// 돌릴 애 있으면 돌리기
		for (int i = 1; i <= 4; i++) {
			// 시계방향 회전
			if (change[i] == 1) {
				int temp = v[i][7];

				for (int j = 6; j >= 0; j--) {
					v[i][j + 1] = v[i][j];
				}

				v[i][0] = temp;
			}
			// 반시계방향 회전
			else if (change[i] == -1) {
				int temp = v[i][0];

				for (int j = 1; j <= 7; j++) {
					v[i][j - 1] = v[i][j];
				}

				v[i][7] = temp;
			}
		}
	}

	if (v[1][0] == 1) {
		answer += 1;
	}
	if (v[2][0] == 1) {
		answer += 2;
	}
	if (v[3][0] == 1) {
		answer += 4;
	}
	if (v[4][0] == 1) {
		answer += 8;
	}

	cout << answer;

	return 0;
}
