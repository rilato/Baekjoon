// 소수점 고정을 위해 cout << fixed 및 cout.precision(3)을 사용한다.
// 소수점 및 %형식을 배열에 저장해야 하므로 동적할당 시 double* arr = new double[N]; 을 사용한다.

#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	double* arr = new double[N];	// double형식으로 저장해야 함

	for (int i = 0; i < N; i++) {
		int num, score;
		double sum = 0;
		double avg;

		cin >> num;

		int* numarr = new int[num];

		for (int j = 0; j < num; j++) {
			cin >> score;
			numarr[j] = score;
			sum += score;
		}

		avg = sum / num;

		int count = 0;

		for (int j = 0; j < num; j++) {
			if (numarr[j] > avg)
				++count;
		}

		arr[i] = (double)count * 100 / num;

		delete[] numarr;
	}

	for (int i = 0; i < N; i++) {
		cout << fixed;		// 소수점을 고정시키기 위함
		cout.precision(3);	// 소수점 아래 세자리 보장
		cout << arr[i] << "%\n";
	}

	delete[] arr;
}