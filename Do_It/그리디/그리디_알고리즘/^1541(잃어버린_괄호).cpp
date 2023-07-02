// 마지막 문자 (NULL)까지 입력받도록 한다.
// if문에서 + - \0를 처리하고, else문에서 숫자를 모아놓는다.

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	string temp = "";
	// - 안나오면 false, - 나오면 true
	bool isMinus = false;
	int result = 0;

	cin >> s;

	// 맨 마지막 문자 NULL까지 받는다.
	for (int i = 0; i <= s.size(); i++) {
		// 여기서 맨 마지막 문자인 NULL에 대해서도 처리한다.
		// 그래야 이 전까지 저장된 temp 값에 대한 계산이 가능해진다.
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			// 음수가 붙은 순간부터 계속 -를 한다.
			if (isMinus) {
				result -= stoi(temp);
			}
			// 음수가 붙지 않은 상태로 판정된 경우 +를 한다.
			else {
				result += stoi(temp);
			}

			temp = "";
			// - 기호를 만난 경우 isMinus = true;
			if (s[i] == '-') {
				isMinus = true;
			}
		}
		// temp 변수에 값 저장
		else {
			temp += s[i];
		}
	}

	cout << result;

	return 0;
}