#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool check[31] = { 0, };
	int num;

	for (int i = 0; i < 28; i++) {
		cin >> num;

		check[num] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!check[i])
			cout << i << '\n';
	}
}