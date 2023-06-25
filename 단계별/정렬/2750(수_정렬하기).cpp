#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int input;
	int num;

	cin >> input;

	int* arr = new int[input];

	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr + input);

	for (int i = 0; i < input; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}



// selection sort

#include <iostream>

using namespace std;

int main() {
	int input, num, min, minIndex, temp;

	cin >> input;

	int* arr = new int[input];

	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[i] = num;
	}

	for (int i = 0; i < input; i++) {
		// ���õ� ������ ������ ��� ���� ���Ͽ� ���� ���� ���� ã�� �۾�
		min = arr[i];

		for (int j = i; j < input; j++) {
			if (arr[j] < min) {
				min = arr[j];
				minIndex = j;
			}
		}

		// ���� ���� ���� ���õ� ���� ���Ͽ� ��ü���ִ� �۾�
		if (min < arr[i]) {
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}

	for (int i = 0; i < input; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}



// insertion sort

#include <iostream>

using namespace std;

int main() {
	int input, num, min, minIndex, temp;

	cin >> input;

	int* arr = new int[input];

	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[i] = num;
	}

	// insertion sort�� �⺻������ n - 1�� ���� ������ ��´�.
	for (int i = 0; i < input - 1; i++) {
		int j = i;

		// �� ����� ���ڸ��� ã�� �� ���� ������ �ϳ��� ��ܰ��� �۾� 
		while (j >= 0 && arr[j] > arr[j + 1]) {
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < input; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}