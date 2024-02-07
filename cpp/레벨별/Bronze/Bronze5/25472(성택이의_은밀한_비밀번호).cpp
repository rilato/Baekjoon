#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	string s;

	cin >> T;

	while (T--) {
		cin >> s;

		if (6 <= s.size() && s.size() <= 9) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}
