#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num;
	vector <int> aliquot;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num;
		aliquot.push_back(num);
	}

	stable_sort(aliquot.begin(), aliquot.end());

	cout << aliquot.front() * aliquot.back();
}