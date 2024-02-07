#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int sum = 0;
	string ans = "";

	cin >> N >> M;

	vector <string> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 열 기준 잡고 행 돌리기
	for (int i = 0; i < M; i++) {
		int arr[4] = { 0, };

		for (int j = 0; j < N; j++) {
			if (v[j][i] == 'A')
				arr[0]++;
			if (v[j][i] == 'C')
				arr[1]++;
			if (v[j][i] == 'G')
				arr[2]++;
			if (v[j][i] == 'T')
				arr[3]++;
		}

		int max = 0;
		int temp = 0;

		for (int j = 0; j < 4; j++) {
			if (arr[j] > max) {
				max = arr[j];
				temp = j;
			}
		}

		if (temp == 0) {
			ans += "A";
		}
		if (temp == 1) {
			ans += "C";
		}
		if (temp == 2) {
			ans += "G";
		}
		if (temp == 3) {
			ans += "T";
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ans[j] != v[i][j])
				sum++;
		}
	}

	cout << ans << '\n' << sum;
}