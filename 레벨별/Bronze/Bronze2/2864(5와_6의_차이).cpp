#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num1, num2;
	string min1 = "";
	string max1 = "";
	string min2 = "";
	string max2 = "";
	int min, max;

	cin >> num1 >> num2;

	for (int i = 0; i < num1.size(); i++) {
		if (num1[i] == '5') {
			min1 += "5";
			max1 += "6";
		}
		else if (num1[i] == '6') {
			min1 += "5";
			max1 += "6";
		}

		else {
			max1 += num1[i];
			min1 += num1[i];
		}
	}

	for (int i = 0; i < num2.size(); i++) {
		if (num2[i] == '5') {
			min2 += "5";
			max2 += "6";
		}
		else if (num2[i] == '6') {
			min2 += "5";
			max2 += "6";
		}
		else {
			max2 += num2[i];
			min2 += num2[i];
		}
	}

	min = stoi(min1) + stoi(min2);
	max = stoi(max1) + stoi(max2);

	cout << min << " " << max;
}