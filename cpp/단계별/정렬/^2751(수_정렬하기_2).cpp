// quick sort는 평균적으로 빠른 알고리즘이지만, 최악의 경우 O(n^2)의 시간 복잡도를 가지므로, 시간 초과가 발생할 수 있다.
// 따라서 quick sort는 사용하지 않는 것이 좋다.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int input;
	int num;

	cin >> input;

	int* arr = new int[input];

	// cin >> num; arr[i] = num;으로 나눠 쓰지 않고, 한번에 줄여서 쓸 수 있다.
	for (int i = 0; i < input; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + input);

	for (int i = 0; i < input; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}



// merge sort
// 1. 분할 2. 정렬 3. 결합의 순서를 거친다.

#include <iostream>
#include <algorithm>

using namespace std;

void merge(int arr[], int left, int right, int mid);
void mergeSort(int arr[], int left, int right);

int main() {
	int input;

	cin >> input;

	int* arr = new int[input];

	for (int i = 0; i < input; i++) {
		cin >> arr[i];
	}

	// 첫 번째 인덱스 값인 0과 마지막 인덱스 값인 input - 1을 인자로 전달한다.
	mergeSort(arr, 0, input - 1);

	for (int i = 0; i < input; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}

// 두 배열의 병합
void merge(int arr[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left, l;
	// 병합한 결과를 담을 배열 my_arr 설정
	int* my_arr = new int[right + 1];

	// arr의 합병
	while (i <= mid && j <= right) {
		// 중간을 기준으로, 앞쪽의 첫 번째 값과 뒤쪽의 첫 번째 값을 비교.
		// 왼쪽 값이 더 작으면
		if (arr[i] <= arr[j])
			my_arr[k++] = arr[i++];	// 앞쪽의 값을 my_arr에 저장 후, 앞쪽의 두번째 인덱스를 가리키도록 함.
		else
			my_arr[k++] = arr[j++];
	}

	// 배열의 앞부분이 모두 my_arr에 옮겨졌다면 (i가 mid + 1이 되었을 것이므로)
	if (i > mid) {
		// 배열의 뒷부분에 남은 데이터들을 my_arr에 그대로 옮김.
		for (l = j; l <= right; l++)
			my_arr[k++] = arr[l];
	}
	// 배열의 뒷부분이 모두 my_arr에 옮겨졌다면
	else {
		// 배열의 앞부분에 남은 데이터들을 my_arr에 그대로 옮김.
		for (l = i; l <= mid; l++)
			my_arr[k++] = arr[l];
	}

	//인자로 온 배열에 값 복사 
	for (l = left; l <= right; l++)
		arr[l] = my_arr[l];

	delete(my_arr);
}

void mergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		// 둘로 나눠서 각각을 정렬
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// 정렬된 두 배열을 병합
		merge(arr, left, mid, right);
	}
}