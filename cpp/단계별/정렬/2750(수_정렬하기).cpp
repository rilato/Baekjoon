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
		// 선택된 수부터 끝까지 모든 수를 비교하여 가장 작은 수를 찾는 작업
		min = arr[i];

		for (int j = i; j < input; j++) {
			if (arr[j] < min) {
				min = arr[j];
				minIndex = j;
			}
		}

		// 가장 작은 수와 선택된 수를 비교하여 교체해주는 작업
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

	// insertion sort는 기본적으로 n - 1번 비교의 기준을 잡는다.
	for (int i = 0; i < input - 1; i++) {
		int j = i;

		// 비교 대상이 제자리를 찾을 때 까지 앞으로 하나씩 당겨가는 작업 
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