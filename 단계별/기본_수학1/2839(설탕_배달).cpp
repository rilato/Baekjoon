#include <iostream>

using namespace std;

int main() {
	int input;
	int min = 5000;

	cin >> input;

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			if (5 * i + 3 * j == input && (i + j) < min)
				min = i + j;
		}
	}

	if (min == 5000)
		cout << -1;
	else
		cout << min;
}