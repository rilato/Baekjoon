// 회의실을 최대한으로 사용할 수 있도록 스케줄링하는 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, start, end;

	cin >> N;

	vector <pair <int, int>> v;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;

		// 정렬을 위해 끝나는 시간을 먼저 넣고, 시작 시간을 나중에 넣음
		v.push_back({ end, start });
	}

	sort(v.begin(), v.end());

	// 끝나는 시간을 기준으로 설정
	int endTime = v[0].first;
	// 맨 처음 회의실 들어간 애 한 개 카운트
	int cnt = 1;

	// 0번째 pair는 이미 entTime으로 설정했으므로, i는 1부터 시작!!
	for (int i = 1; i < N; i++) {
		int startTime = v[i].second;

		if (startTime >= endTime) {
			// 종료시간 업데이트
			endTime = v[i].first;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}