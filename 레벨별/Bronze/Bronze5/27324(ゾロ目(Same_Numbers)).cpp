#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	cin >> s;

	if (s[0] == s[1])
		cout << 1;
	else
		cout << 0;

	return 0;
}
