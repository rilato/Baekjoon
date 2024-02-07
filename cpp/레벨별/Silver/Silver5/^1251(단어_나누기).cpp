// 원리는 https://jokerkwu.tistory.com/50 참고

// 틀린 코드

// cabadd와 같은 예외 케이스
// 즉 a같이 가장 작은 문자가 두 번 나오는 경우를 고려한다.

// 가장 작은 문자 두 개를 골라서 뒤집는 것이 아니라,
// 뒤집었을 때 사전순으로 가장 앞에 나와야 하므로,
// 모든 경우를 탐색해본다.

#include <iostream>

using namespace std;

int main() {
	string word;
	int len;
	// z 다음의 아스키코드가 {
	char min = '{';
	char min2 = '{';
	int index = 0;
	int index2 = 0;

	cin >> word;

	len = word.size();

	for (int i = 0; i < len; i++) {
		if (word[i] < min) {
			min = word[i];
			index = i;
		}
	}

	for (int i = 0; i < len; i++) {
		if (word[i] < min2&& i != index) {
			min2 = word[i];
			index2 = i;
		}
	}

	for (int i = index; i >= 0; i--) {
		cout << word[i];
	}

	for (int i = index2; i > index; i--) {
		cout << word[i];
	}

	for (int i = len; i > index2; i--) {
		cout << word[i];
	}
}




// 맞은 코드

#include <iostream>
#include <string>
using namespace std;

string input, result;
string a, b;

int main() {
	cin >> input;

	result = "{";

	for (int i = 0; i < input.size() - 2; i++) {
		for (int j = i + 1; j < input.size() - 1; j++) {

			string val;

			for (int u = i; u >= 0; u--)
				val += input[u];

			for (int u = j; u > i; u--)
				val += input[u];

			for (int u = input.size() - 1; u > j; u--)
				val += input[u];

			if (result > val) result = val;
		}
	}

	cout << result << endl;
}

