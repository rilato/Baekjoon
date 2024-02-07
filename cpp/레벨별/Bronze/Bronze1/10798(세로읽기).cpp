#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char arr[5][15] = { 0, };
	string s;

	for (int i = 0; i < 5; i++) {
		getline(cin, s);

		for (int j = 0; j < s.size(); j++)
			arr[i][j] = s[j];
	}

	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if (!arr[i][j])
				continue;

			cout << arr[i][j];
		}
	}
}