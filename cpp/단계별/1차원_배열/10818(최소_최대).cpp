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


// 다른 방법

#include <iostream>

using namespace std;

int main()
{
	int N, input;
	int min = 1000000;  // 아래의 min 조건에 맞추기 위해서, min을 최대값으로 설정
	int max = -1000000; // 아래의 max 조건에 맞추기 위해서, max를 최소값으로 설정


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