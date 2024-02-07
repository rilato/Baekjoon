#include <iostream>

using namespace std;

int T, Y, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		int Ysum = 0;
		int Ksum = 0;

		for (int i = 0; i < 9; i++) {
			cin >> Y >> K;

			Ysum += Y;
			Ksum += K;
		}

		if (Ysum > Ksum)
			cout << "Yonsei\n";
		else if (Ysum < Ksum)
			cout << "Korea\n";
		else
			cout << "Draw\n";
	}
}