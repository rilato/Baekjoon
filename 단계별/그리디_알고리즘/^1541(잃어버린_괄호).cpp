// https://tooo1.tistory.com/146
// bool을 이용한다.
// -가 한 번 등장하는 순간, +가 나오더라도 괄호에 묶여 -로 처리되도록 한다.
// 즉, -가 한 번 나오면 그 뒤의 숫자는 무조건 빼준다.


#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	string temp = "";
	int result = 0;
	bool isMinus = false;

	cin >> S;

	// 맨 마지막 문자 NULL까지 받는다.
	for (int i = 0; i <= S.size(); i++) {
		// 여기서 맨 마지막 문자인 NULL에 대해서도 처리한다.
		// 그래야 이 전까지 저장된 temp 값에 대한 계산이 가능해진다.
		if (S[i] == '+' || S[i] == '-' || S[i] == '\0') {
			// 음수가 붙은 순간부터 계속 -를 한다.
			if (isMinus) {
				result -= stoi(temp);
			}
			// 음수가 붙지 않은 상태로 판정된 경우 +를 한다.
			else {
				result += stoi(temp);
			}
			temp = "";
			// - 기호를 만난 경우 체크
			if (S[i] == '-') {
				isMinus = true;
			}
		}
		// temp 변수에 값 저장
		else {
			temp += S[i];
		}
	}

	cout << result;
}