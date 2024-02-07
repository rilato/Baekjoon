#include <iostream>

using namespace std;

int main() {
	int theNumberOfCard, num, cardNumber;
	int i, j, k, sum = 0;
	int max = 0;

	cin >> theNumberOfCard >> num;

	int* arr = new int[theNumberOfCard];

	for (int i = 0; i < theNumberOfCard; i++) {
		cin >> cardNumber;
		arr[i] = cardNumber;
	}

	for (i = 0; i < theNumberOfCard; i++) {
		for (j = 0; j < theNumberOfCard; j++) {
			for (k = 0; k < theNumberOfCard; k++) {
				if (i != j && j != k && k != i)
					sum = arr[i] + arr[j] + arr[k];
				if (sum <= num && sum >= max)
					max = sum;
			}
		}
	}

	cout << max;

	delete[] arr;
}