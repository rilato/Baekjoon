#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	string ans = "";

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (islower(s[i]))
			ans += toupper(s[i]);
		else
			ans += tolower(s[i]);
	}

	cout << ans;
}