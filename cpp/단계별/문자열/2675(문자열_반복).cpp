#include <iostream>
#include <string>

using namespace std;

int main()
{
	int inputNum;
	int repeatNum;
	string word;
	string alphabet;

	cin >> inputNum;

	for (int i = 0; i < inputNum; i++) {
		cin >> repeatNum;
		cin >> word;

		for (int j = 0; j < word.size(); j++) {
			alphabet = word.substr(j, 1);

			for (int k = 0; k < repeatNum; k++)
				cout << alphabet;
		}

		cout << '\n';
	}
}