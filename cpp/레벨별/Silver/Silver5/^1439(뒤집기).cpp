// Ʋ�� Ǯ��
// �ݷʰ� �ִ� �� �ϴ�

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	char temp = ' ';
	int cntZero = 0;
	int cntOne = 0;

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (temp != S[i]) {
			if (temp == '1')
				cntOne++;
			else if (temp == '0')
				cntZero++;
		}

		temp = S[i];
	}

	if (cntOne == 0 || cntZero == 0)
		cout << max(cntOne, cntZero);
	else
		cout << min(cntOne, cntZero);
}


// ���� Ǯ��

#include <iostream>

using namespace std;

int main() {
	string s;
	int result = 0;

	cin >> s;

	for (int i = 0; i < s.length(); i++)
		if (s[i] != s[i + 1])
			result++;

	if (!result)
		cout << result;
	// �ߺ��� count�� �����ϱ� ���� 2�� ������.
	else
		cout << result / 2;
}