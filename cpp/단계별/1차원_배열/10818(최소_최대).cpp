#include <iostream>

using namespace std;

int main()
{
	int N, input;
	int min, max;


	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
	}

	min = arr[0];
	max = arr[0];

	for (int i = 0; i < N; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	cout << min << " " << max;

	delete[] arr;
}


// �ٸ� ���

#include <iostream>

using namespace std;

int main()
{
	int N, input;
	int min = 1000000;  // �Ʒ��� min ���ǿ� ���߱� ���ؼ�, min�� �ִ밪���� ����
	int max = -1000000; // �Ʒ��� max ���ǿ� ���߱� ���ؼ�, max�� �ּҰ����� ����


	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> input;

		arr[i] = input;

		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	cout << min << " " << max;

	delete[] arr;
}