#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	bool check = false;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			cout << " ";
		}

		cout << "*";

		if (!check) {
			check = true;
			cout << '\n';
			continue;
		}

		for (int j = 0; j < 2 * i - 1; j++) {
			cout << " ";
		}

		cout << "*";

		cout << '\n';
	}
}