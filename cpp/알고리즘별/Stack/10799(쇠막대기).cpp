// ( -> 스택에 푸시
// ) -> 이전 값이 (라면, 레이저를 생성 -> ( 한 개 pop한 후 stack의 size만큼 +
//	 -> 이전 값이 )라면, 막대기 1개 추가

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	stack <char> S;
	int answer = 0;

	cin >> input;

	// 맨 앞에 (을 넣고 시작
	// 왜냐하면 아래의 for문에서 i - 1 인덱스를 사용하면서, i = 1부터 시작하기 때문.
	S.push('(');

	for (int i = 1; i < input.size(); i++) {
		char temp = input[i - 1];

		if (input[i] == '(') {
			S.push('(');
		}
		// input[i] == ')'
		else {
			// 이전 값이 (이고, 현재 값이 )라면, 레이저를 형성
			if (temp == '(') {
				if (!S.empty()) {
					S.pop();	// 레이저 형성을 위해 한 개 빼기
					answer += S.size();
				}
			}
			else {
				if (!S.empty()) {
					S.pop();
					answer++;
				}
			}
		}
	}

	cout << answer;

	return 0;
}