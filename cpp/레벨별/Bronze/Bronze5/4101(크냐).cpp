#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num1, num2;

	while (1) {
		cin >> num1 >> num2;

		if (!num1 && !num2)
			break;

		if (num1 > num2)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}