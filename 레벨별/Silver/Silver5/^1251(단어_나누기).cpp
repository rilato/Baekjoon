// ������ https://jokerkwu.tistory.com/50 ����

// Ʋ�� �ڵ�

// cabadd�� ���� ���� ���̽�
// �� a���� ���� ���� ���ڰ� �� �� ������ ��츦 ����Ѵ�.

// ���� ���� ���� �� ���� ��� ������ ���� �ƴ϶�,
// �������� �� ���������� ���� �տ� ���;� �ϹǷ�,
// ��� ��츦 Ž���غ���.

#include <iostream>

using namespace std;

int main() {
	string word;
	int len;
	// z ������ �ƽ�Ű�ڵ尡 {
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




// ���� �ڵ�

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

