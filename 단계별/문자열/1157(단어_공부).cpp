#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string input;
	int alphabet[26] = { 0, };

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (islower(input[i]))
			alphabet[input[i] - 'a']++;
		else
			alphabet[input[i] - 'A']++;
	}

	int max = 0;

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max)
			max = alphabet[i];
	}

	int count = 0;
	int index;

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == max) {
			index = i;
			++count;
		}
	}

	if (count >= 2)
		cout << '?';
	else
		cout << char('A' + index);
}