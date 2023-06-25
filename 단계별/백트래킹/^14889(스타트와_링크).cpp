// 아이패드 필기 참고

#include <iostream>
#include <cmath>

using namespace std;

int N;
int minimum = 100;
int arr[20][20];
bool visited[20];

void bt(int cnt, int cur);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	// 카운트는 0부터 시작, 숫자는 -1부터 시작
	bt(0, -1);

	cout << minimum;
}

// cnt는 카운트 수, 즉 깊이를 나타낸다.
// cur은 현재 저장되어있는 인덱스의 값을 의미한다.
void bt(int cnt, int cur) {
	// 카운트 수가 정원의 절반이 되었을 때 능력치의 합 계산 후 차를 계산
	if (cnt == N / 2) {
		int start = 0;
		int link = 0;

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visited[i] && visited[j]) {
					start += arr[i][j] + arr[j][i];
				}
				if (!visited[i] && !visited[j]) {
					link += arr[i][j] + arr[j][i];
				}
			}
		}

		minimum = min(minimum, abs(start - link));
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i] && i > cur) {
			visited[i] = true;
			bt(cnt + 1, i);
			// 복원
			visited[i] = false;
		}
	}
}