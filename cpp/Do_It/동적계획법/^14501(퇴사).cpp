// N이 아닌, N + 1까지 살펴야 한다!!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <pair <int, int>> v;	// {걸리는 일 수, 비용} 저장
int answer[17] = { 0, };	// 최대 수익 저장 배열. N = 15일 때 사실상 16까지 계산해야 하므로, 0 ~ 16까지의 인덱스를 사용할 수 있도록 17을 쓸 것!!

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N + 1);
	
	for (int i = 1; i <= N; i++) {
		int T, P;
		
		cin >> T >> P;
		
		v[i] = { T, P };
	}


	for (int i = N; i >= 1; i--) {
		// 현재 보고 있는 날짜 + 걸리는 날짜가 최종 날짜 N + 1과 같거나 앞서야 최대 수익 갱신 가능.
		// N + 1을 사용해야 하는 이유 : N = 10이고, 10번째 입력 값에서 시간이 하루 걸린다고 하면, 그 날에 해결 가능하므로 사실상 N = 11일 때 까지 봐야 함.
		if (i + v[i].first <= N + 1) {
			answer[i] = max(answer[i + 1], answer[i + v[i].first] + v[i].second);
		}
		// 현재 보고있는 날짜를 넘어간다면, 이전 날짜의 수익을 그대로 갖다 써야 함
		else {
			answer[i] = answer[i + 1];
		}
	}

	cout << answer[1] << '\n';

	return 0;
}
