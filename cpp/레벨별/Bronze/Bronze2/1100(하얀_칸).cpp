#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char input;
	int count = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> input;

			if (input == 'F' && (!(i % 2) && !(j % 2) || (i % 2) && (j % 2)))
				count++;
		}
	}

	cout << count;
}