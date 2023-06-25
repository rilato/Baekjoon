#include <iostream>
#include <string>

using namespace std;

int main()
{
	int input;
	string num;
	int sum = 0;
	int number;

	cin >> input;

	cin >> num;

	for (int i = 0; i < num.size(); i++) {
		number = stoi(num.substr(i, 1));
		sum += number;
	}

	cout << sum;
}