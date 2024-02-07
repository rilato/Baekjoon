#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	int cute = 0;
	int notcute = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num;

		if (num)
			cute++;
		else
			notcute++;
	}

	if (cute > notcute)
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";
}