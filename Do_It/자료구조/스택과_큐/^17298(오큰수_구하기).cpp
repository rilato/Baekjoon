// 스택을 활용하되, 스택에는 벡터의 인덱스를 저장한다.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, top;
	stack <int> s;

	cin >> N;

	// 하단처럼 ans의 인덱스에 바로 접근하여 값을 저장하기 위해서는, 배열의 사이즈를 지정해줘야 한다!
	vector <int> v(N, 0);
	vector <int> ans(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 스택에는 벡터의 인덱스를 푸시
	s.push(0);

	for (int i = 1; i < N; i++) {
		// 스택이 비지 않았고, 현재 수열이 스택 top 위치의 값보다 크다면
		while (!s.empty() && v[s.top()] < v[i]) {
			ans[s.top()] = v[i];	// 현재의 값(오큰수)을 ans 배열에 저장
			s.pop();	// 스택의 top을 제거
		}

		s.push(i);
	}

	// 반복문을 다 돌고 나왔는데 스택이 비어있지 않은 경우, 빌 때까지 -1
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}