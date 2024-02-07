// 가장 먼저 getline함수를 정확하게 익힐 필요가 있다.

// 다음으로 문자열 처리 시 반례를 찾는 경우다.
// 문자열을 stack으로 처리 시 잘못된 문자열인지 판별을 하는 방법이
// 1. ) ] 가 등장했는데 스택이 비어있는 경우
// 2. 문자열의 끝까지 검사했는데 스택에 뭔가 남아있는 경우
// 두 가지 뿐이다.
// 이 두가지 경우를 모두 고려해서 예외 처리를 해야한다.

#include <iostream>
#include <string>

using namespace std;

char stack[100];
int tos = -1;

void push(char c);
bool pop(char c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string sentence;
		bool answer = true;

		// 문장 단위는 '\n'으로 구분하고, 입력의 끝은 .으로 끝나야 한다.
		// 따라서 문장을 받을 때에는 '\n'을 기준으로 구분하기 위해 아래에서는 이렇게 썼다.
		getline(cin, sentence);

		// 문자열의 첫 번째 글자 접근을 위해 인덱싱 [0] 처리.
		// .을 통해 탈출을 위해 아래와 같이 썼다.
		if (sentence.size() == 1 && sentence[0] == '.')
			break;

		for (int i = 0; i < sentence.size(); i++) {
			char alphabet = sentence[i];

			if (sentence[i] == '(')
				push('(');
			if (sentence[i] == '[')
				push('[');
			if (sentence[i] == ')')
				answer = pop(')');
			if (sentence[i] == ']')
				answer = pop(']');

			if (answer == false)
				break;
		}

		// 여기서 tos != -1인 부분을 추가하지 않으면, 반례가 발생했다.
		// ()[]( 처럼, 균형을 이뤘지만, 마지막에 push가 발생한 경우 yes로 표기되었다.

		if (tos != -1 || answer == false) {
			tos = -1;
			cout << "no" << '\n';
		}
		else
			cout << "yes" << '\n';
	}
}


void push(char c) {
	if (c == '(')
		stack[++tos] = '(';
	if (c == '[')
		stack[++tos] = '[';
}

bool pop(char c) {
	if (c == ')' && stack[tos] == '(') {
		stack[tos--] = NULL;
		return true;
	}

	if (c == ']' && stack[tos] == '[') {
		stack[tos--] = NULL;
		return true;
	}

	return false;
}