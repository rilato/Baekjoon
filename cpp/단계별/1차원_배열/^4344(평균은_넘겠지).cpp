// �Ҽ��� ������ ���� cout << fixed �� cout.precision(3)�� ����Ѵ�.
// �Ҽ��� �� %������ �迭�� �����ؾ� �ϹǷ� �����Ҵ� �� double* arr = new double[N]; �� ����Ѵ�.

#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	double* arr = new double[N];	// double�������� �����ؾ� ��

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
		cout << fixed;		// �Ҽ����� ������Ű�� ����
		cout.precision(3);	// �Ҽ��� �Ʒ� ���ڸ� ����
		cout << arr[i] << "%\n";
	}

	delete[] arr;
}