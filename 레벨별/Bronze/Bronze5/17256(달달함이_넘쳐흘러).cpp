#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ax, ay, az;
	int bx, by, bz;
	int cx, cy, cz;

	cin >> ax >> ay >> az;
	cin >> cx >> cy >> cz;

	cout << cx - az << " " << cy / ay << " " << cz - ax;

	return 0;
}