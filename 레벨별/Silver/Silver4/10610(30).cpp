// ������ 3�� ����̰�, 0�� ���ԵǾ��ִٸ�, ������������ ������ ���� ���� ū ���� �ȴ�.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	long long sum = 0;
	bool check = false;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			check = true;
		sum += s[i] - '0';
	}

	// ��� �ڸ����� ���� 3�� ����� �ƴ϶��
	if (sum % 3)
		check = false;

	if (!check) {
		cout << -1;
		return 0;
	}

	// 3�� ����̰�, 0�� ���ԵǾ��ִٸ�, ������������ ������ ���� ���� ū ���� �ȴ�.
	sort(s.begin(), s.end(), greater<>());

	cout << s;
}