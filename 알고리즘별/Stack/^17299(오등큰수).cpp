#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector <int> v;
	vector <int> cnt;
	vector <int> answer;
	stack <int> s;

	cin >> N;

	v.resize(N);
	answer.resize(N, -1);
	cnt.resize(1000001, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];

		cnt[v[i]]++;
	}

	for (int i = 0; i < N; i++) {
		// 스택이 비지 않았고, 현재 수열의 cnt값이 스택 top 위치의 값을 갖는 cnt보다 크다면
		while (!s.empty() && cnt[v[s.top()]] < cnt[v[i]]) {
			answer[s.top()] = v[i];	// 현재 보고있는 값(오등큰수)을 answer 배열에 저장
			s.pop();				// 스택의 top을 제거
		}

		s.push(i);
	}

	for (int ans : answer) {
		cout << ans << " ";
	}

	return 0;
}