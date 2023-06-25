#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int in, out;
	int sum = 0;
	int max = 0;

	for (int i = 0; i < 10; i++) {
		cin >> out >> in;

		sum -= out;

		if (max < sum)
			max = sum;

		sum += in;

		if (max < sum)
			max = sum;
	}

	cout << max;
}