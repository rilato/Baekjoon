#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	int cnt = 0;
	int dcnt = 0;
	int arr[8] = { 0, };

	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	for (int i = 0; i < 7; i++) {
		if (arr[i] < arr[i + 1])
			cnt++;

		if (arr[i] > arr[i + 1])
			dcnt++;
	}

	if (cnt == 7) {
		cout << "ascending";
		return 0;
	}
	else if (dcnt == 7) {
		cout << "descending";
		return 0;
	}
	else
		cout << "mixed";
}