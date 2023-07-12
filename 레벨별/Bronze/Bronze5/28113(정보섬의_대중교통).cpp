#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;

	cin >> n >> a >> b;

	if (a < b) {
		cout << "Bus";
	}
	else if (a > b) {
		cout << "Subway";
	}
	else {
		cout << "Anything";
	}

	return 0;
}
