// ( -> ���ÿ� Ǫ��
// ) -> ���� ���� (���, �������� ���� -> ( �� �� pop�� �� stack�� size��ŭ +
//	 -> ���� ���� )���, ����� 1�� �߰�

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

	// �� �տ� (�� �ְ� ����
	// �ֳ��ϸ� �Ʒ��� for������ i - 1 �ε����� ����ϸ鼭, i = 1���� �����ϱ� ����.
	S.push('(');

	for (int i = 1; i < input.size(); i++) {
		char temp = input[i - 1];

		if (input[i] == '(') {
			S.push('(');
		}
		// input[i] == ')'
		else {
			// ���� ���� (�̰�, ���� ���� )���, �������� ����
			if (temp == '(') {
				if (!S.empty()) {
					S.pop();	// ������ ������ ���� �� �� ����
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