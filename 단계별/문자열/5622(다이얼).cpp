#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	int sum = 0;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'C')
			sum += 3;
		if (input[i] >= 'D' && input[i] <= 'F')
			sum += 4;
		if (input[i] >= 'G' && input[i] <= 'I')
			sum += 5;
		if (input[i] >= 'J' && input[i] <= 'L')
			sum += 6;
		if (input[i] >= 'M' && input[i] <= 'O')
			sum += 7;
		if (input[i] >= 'P' && input[i] <= 'S')
			sum += 8;
		if (input[i] >= 'T' && input[i] <= 'V')
			sum += 9;
		if (input[i] >= 'W' && input[i] <= 'Z')
			sum += 10;
	}

	cout << sum;
}


// 다른 풀이

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	int index;
	int arr[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

	int sum = 0;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		index = input[i] - 'A';
		sum += arr[index];
	}

	cout << sum;
}