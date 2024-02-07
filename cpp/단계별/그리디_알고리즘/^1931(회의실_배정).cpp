// 그리디 알고리즘 중 스케줄링을 이용한다.
// https://cocoon1787.tistory.com/147
// 아이패드 필기 확인

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, time;
	int count = 1;

	cin >> N;

	vector <pair <int, int>> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].second >> v[i].first;

	// 회의가 끝나는 시간을 기준으로 정렬
	sort(v.begin(), v.end());

	// 최초로 회의가 끝나는 시간을 time에 저장
	time = v[0].first;

	for (int i = 1; i < N; i++) {
		// 회의 시작 시간이 회의가 끝나는 시간과 같거나 늦는 경우
		if (time <= v[i].second) {
			// 해당 회의시간의 끝을 time으로 만들어주고 1회 증가
			time = v[i].first;
			count++;
		}
	}

	cout << count;
}