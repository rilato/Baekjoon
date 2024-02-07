#include <iostream>
#include <vector>

using namespace std;

int N, T, P;
vector <pair <int, int>> v;
vector <int> answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// N + 1일까지 계산해야하므로 v보다 1개 더 공간을 확보한다.
	answer.resize(N + 1);

	for (int i = 0; i < N; i++) {
		cin >> T >> P;

		v.push_back({ T, P });
	}

	// i는 0일부터 시작하므로, 마지막으로 상담 가능한 날짜는 N - 1이고,
	// 상담이 가능한 숫자는 N으로 설정한다.
	for (int i = N - 1; i >= 0; i--) {
		if (i + v[i].first <= N) {
			answer[i] = max(answer[i + 1], v[i].second + answer[i + v[i].first]);
		}
		else {
			answer[i] = answer[i + 1];
		}
	}

	cout << answer[0];

	return 0;
}