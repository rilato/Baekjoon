#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;

	cin >> S;

	if (S == "NLCS") {
		cout << "North London Collegiate School";
	}
	else if (S == "BHA") {
		cout << "Branksome Hall Asia";
	}
	else if (S == "KIS") {
		cout << "Korea International School";
	}
	else {
		cout << "St. Johnsbury Academy";
	}
}