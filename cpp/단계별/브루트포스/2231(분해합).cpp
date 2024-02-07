#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;

	cin >> num;

	int min = num;

	for (int i = 1; i < num; i++) {
		int sum = 0;
		string NUM = to_string(i);

		for (int j = 0; j < NUM.size(); j++) {
			sum += stoi(NUM.substr(j, 1));
		}

		sum += i;

		if (sum == num && i <= min)
			min = i;
	}

	if (min == num)
		cout << 0;
	else
		cout << min;
}