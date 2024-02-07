#include <iostream>

using namespace std;

int main()
{
	int N;
	int input;
	int max = 0;
	double sum = 0;
	double avg;

	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;

		if (arr[i] > max)
			max = arr[i];
	}

	for (int i = 0; i < N; i++)
		sum += ((double)arr[i] / max * 100);

	avg = sum / N;

	cout << avg;

	delete[] arr;
}