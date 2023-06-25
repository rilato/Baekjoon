// ���� ���� getline�Լ��� ��Ȯ�ϰ� ���� �ʿ䰡 �ִ�.

// �������� ���ڿ� ó�� �� �ݷʸ� ã�� ����.
// ���ڿ��� stack���� ó�� �� �߸��� ���ڿ����� �Ǻ��� �ϴ� �����
// 1. ) ] �� �����ߴµ� ������ ����ִ� ���
// 2. ���ڿ��� ������ �˻��ߴµ� ���ÿ� ���� �����ִ� ���
// �� ���� ���̴�.
// �� �ΰ��� ��츦 ��� ����ؼ� ���� ó���� �ؾ��Ѵ�.

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

		// ���� ������ '\n'���� �����ϰ�, �Է��� ���� .���� ������ �Ѵ�.
		// ���� ������ ���� ������ '\n'�� �������� �����ϱ� ���� �Ʒ������� �̷��� ���.
		getline(cin, sentence);

		// ���ڿ��� ù ��° ���� ������ ���� �ε��� [0] ó��.
		// .�� ���� Ż���� ���� �Ʒ��� ���� ���.
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

		// ���⼭ tos != -1�� �κ��� �߰����� ������, �ݷʰ� �߻��ߴ�.
		// ()[]( ó��, ������ �̷�����, �������� push�� �߻��� ��� yes�� ǥ��Ǿ���.

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