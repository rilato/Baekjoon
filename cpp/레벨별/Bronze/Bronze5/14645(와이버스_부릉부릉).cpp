#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	cin >> s;

	string fan = ":fan:";

	cout << fan << fan << fan << "\n";
	cout << fan << ":" << s << ":" << fan << "\n";
	cout << fan << fan << fan;

	return 0;
}