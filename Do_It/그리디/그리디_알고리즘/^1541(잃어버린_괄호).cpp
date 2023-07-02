// ������ ���� (NULL)���� �Է¹޵��� �Ѵ�.
// if������ + - \0�� ó���ϰ�, else������ ���ڸ� ��Ƴ��´�.

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	string temp = "";
	// - �ȳ����� false, - ������ true
	bool isMinus = false;
	int result = 0;

	cin >> s;

	// �� ������ ���� NULL���� �޴´�.
	for (int i = 0; i <= s.size(); i++) {
		// ���⼭ �� ������ ������ NULL�� ���ؼ��� ó���Ѵ�.
		// �׷��� �� ������ ����� temp ���� ���� ����� ����������.
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			// ������ ���� �������� ��� -�� �Ѵ�.
			if (isMinus) {
				result -= stoi(temp);
			}
			// ������ ���� ���� ���·� ������ ��� +�� �Ѵ�.
			else {
				result += stoi(temp);
			}

			temp = "";
			// - ��ȣ�� ���� ��� isMinus = true;
			if (s[i] == '-') {
				isMinus = true;
			}
		}
		// temp ������ �� ����
		else {
			temp += s[i];
		}
	}

	cout << result;

	return 0;
}