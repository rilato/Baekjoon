#include <iostream>

using namespace std;

int T, K;
int arr[46];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 45; i++)
		arr[i] = arr[i - 1] + i;

	cin >> T;

	while (T--) {
		bool check = false;

		cin >> K;

		for (int i = 1; i <= 45; i++) {
			for (int j = 1; j <= 45; j++) {
				for (int k = 1; k <= 45; k++) {
					if (arr[i] + arr[j] + arr[k] == K)
						check = true;
				}
			}
		}

		if (check)
			cout << 1;
		else
			cout << 0;

		cout << '\n';
	}
}