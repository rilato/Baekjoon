#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	int min = 1000;

	cin >> x >> y >> w >> h;

	if (h - y < min)
		min = h - y;
	if (w - x < min)
		min = w - x;
	if (x < min)
		min = x;
	if (y < min)
		min = y;

	cout << min;
}