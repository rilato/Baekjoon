// ignore()�� ������ ������.

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;

	cin >> n;

	// ignore�� ����� n �ڿ� ���͸� �Է¹��� �ʰ�, getline() ����!
	cin.ignore();

	for (int i = 1; i <= n; i++) {
		getline(cin, s);

		cout << i << ". " << s << '\n';
	}
}