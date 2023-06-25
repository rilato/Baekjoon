#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;

	while (1) {
		getline(cin, S);

		if (S == "END")
			break;

		for (int i = S.size() - 1; i >= 0; i--) {
			cout << S[i];
		}

		cout << '\n';
	}
}