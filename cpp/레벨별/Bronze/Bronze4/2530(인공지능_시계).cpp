#include <iostream>

using namespace std;

int main() {
	int hour, minute, second, time;
	cin >> hour >> minute >> second >> time;

	second += time;
	minute += second / 60;
	hour += minute / 60;

	cout << hour % 24 << " " << minute % 60 << " " << second % 60;
}