#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V;
	int arr[2] = { 0, 0 };

	cin >> V;

	for (int i = 0; i < V; i++) {
		char character;

		cin >> character;

		(character == 'A') ? arr[0]++ : arr[1]++;
	}

	if (arr[0] > arr[1])
		cout << "A";
	else if (arr[0] < arr[1])
		cout << "B";
	else
		cout << "Tie";
}