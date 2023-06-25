#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long S;
	int count = 0;

	cin >> S;

	int i = 1;

	while (1) {
		if (S < 0) {
			count--;
			break;
		}

		S -= i;
		count++;
		i++;
	}

	cout << count;
}