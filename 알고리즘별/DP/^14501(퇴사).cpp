// https://velog.io/@sj-lee33/%EB%B0%B1%EC%A4%80-14501%EB%B2%88-%ED%87%B4%EC%82%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-c-%ED%92%80%EC%9D%B4

// 스케줄링의 일환 같은 문제로 보인다.
// 뒤쪽부터 탐색한다.

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Ti[16] = { 0, };
int Pi[16] = { 0, };
int res[16] = { 0, };	// 배열 인덱스의 뒤쪽부터 계산해 나감. res[1]이 최종적인 Max값

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> Ti[i] >> Pi[i];
	}

	int deadline;

	for (int i = N; i > 0; i--) {
		deadline = i + Ti[i];
		if (deadline > N + 1) {
			// 상담 불가시 이전 최대 값을 그대로 갖다 씀
			res[i] = res[i + 1];
		}
		else {
			// 상담 가능, 최대 이익 판별 필요 (해당 날짜를 진행했을 경우와, 그렇지 않았을 경우를 비교)
			res[i] = max(res[i + 1], res[deadline] + Pi[i]);
		}
	}

	cout << res[1];

	return 0;
}