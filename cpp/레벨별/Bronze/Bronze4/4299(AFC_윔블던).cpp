#include <iostream>

using namespace std;

int main() {
	int sum, difference, winner, loser;

	cin >> sum >> difference;

	for (int i = 0; i <= sum; i++) {
		winner = i;
		loser = sum - i;

		if (winner - loser == difference) {
			cout << winner << ' ' << loser;
			return 0;
		}
	}

	cout << -1;
}