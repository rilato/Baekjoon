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





#include <iostream>
#include <vector>

using namespace std;

int N, T, P;
int answer = 0;
vector <pair <int, int>> v;
vector <int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp.resize(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> T >> P;

        v.push_back({ T, P });
    }

    for (int i = N - 1; i >= 0; i--) {
        // i : 오늘 날짜, v[i].first : 걸리는 일 수, N : 마무리해야하는 날짜
        int finishDay = i + v[i].first;
        // 상담 가능 날짜라면, i + 1날 까지의 최대 이익과, 오늘 수당 + 마무리 날 수당의 최대 이익을 비교
        if (finishDay <= N) {
            dp[i] = max(dp[i + 1], v[i].second + dp[finishDay]);
        }
        // 상담 불가능한 날짜라면, i + 1날 까지의 최대 이익을 그대로 반영
        else {
            dp[i] = dp[i + 1];
        }

        answer = max(answer, dp[i]);
    }

    cout << answer;

    return 0;
}
