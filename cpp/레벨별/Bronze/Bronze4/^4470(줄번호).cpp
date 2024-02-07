// ignore()의 사용법을 익힌다.

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

	// ignore를 써줘야 n 뒤에 엔터를 입력받지 않고, getline() 가능!
	cin.ignore();

	for (int i = 1; i <= n; i++) {
		getline(cin, s);

		cout << i << ". " << s << '\n';
	}
}