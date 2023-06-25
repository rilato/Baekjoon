#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, r, e, c;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> r >> e >> c;

		if (r < e - c)
			cout << "advertise\n";
		else if (r > e - c)
			cout << "do not advertise\n";
		else
			cout << "does not matter\n";
	}
}