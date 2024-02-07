#include <iostream>
#include <cmath>

using namespace std;

int countPrimeNumber(int num);
bool isPrimeNumber(int num);

int main() {
	int num;

	while (1) {
		cin >> num;

		if (!num)	// num == 0인 경우
			break;

		cout << countPrimeNumber(num) << '\n';
	}
}

int countPrimeNumber(int num) {
	int count = 0;

	for (int i = num + 1; i <= num * 2; i++) {
		if (isPrimeNumber(i))
			++count;
	}

	return count;
}

bool isPrimeNumber(int num) {
	int root = sqrt(num);

	for (int i = 2; i <= root; i++) {
		if (!(num % i))		// num == 0인 경우
			return 0;
	}

	return 1;
}