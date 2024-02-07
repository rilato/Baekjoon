#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	int row, column;
	int max = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> num;

			if (num >= max) {
				row = i;
				column = j;
				max = num;
			}
		}
	}

	cout << max << '\n' << row + 1 << " " << column + 1;
}