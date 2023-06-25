// quick sort�� ��������� ���� �˰���������, �־��� ��� O(n^2)�� �ð� ���⵵�� �����Ƿ�, �ð� �ʰ��� �߻��� �� �ִ�.
// ���� quick sort�� ������� �ʴ� ���� ����.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int input;
	int num;

	cin >> input;

	int* arr = new int[input];

	// cin >> num; arr[i] = num;���� ���� ���� �ʰ�, �ѹ��� �ٿ��� �� �� �ִ�.
	for (int i = 0; i < input; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + input);

	for (int i = 0; i < input; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}



// merge sort
// 1. ���� 2. ���� 3. ������ ������ ��ģ��.

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

	// ù ��° �ε��� ���� 0�� ������ �ε��� ���� input - 1�� ���ڷ� �����Ѵ�.
	mergeSort(arr, 0, input - 1);

	for (int i = 0; i < input; i++)
		cout << arr[i] << '\n';

	delete[] arr;
}

// �� �迭�� ����
void merge(int arr[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left, l;
	// ������ ����� ���� �迭 my_arr ����
	int* my_arr = new int[right + 1];

	// arr�� �պ�
	while (i <= mid && j <= right) {
		// �߰��� ��������, ������ ù ��° ���� ������ ù ��° ���� ��.
		// ���� ���� �� ������
		if (arr[i] <= arr[j])
			my_arr[k++] = arr[i++];	// ������ ���� my_arr�� ���� ��, ������ �ι�° �ε����� ����Ű���� ��.
		else
			my_arr[k++] = arr[j++];
	}

	// �迭�� �պκ��� ��� my_arr�� �Ű����ٸ� (i�� mid + 1�� �Ǿ��� ���̹Ƿ�)
	if (i > mid) {
		// �迭�� �޺κп� ���� �����͵��� my_arr�� �״�� �ű�.
		for (l = j; l <= right; l++)
			my_arr[k++] = arr[l];
	}
	// �迭�� �޺κ��� ��� my_arr�� �Ű����ٸ�
	else {
		// �迭�� �պκп� ���� �����͵��� my_arr�� �״�� �ű�.
		for (l = i; l <= mid; l++)
			my_arr[k++] = arr[l];
	}

	//���ڷ� �� �迭�� �� ���� 
	for (l = left; l <= right; l++)
		arr[l] = my_arr[l];

	delete(my_arr);
}

void mergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		// �ѷ� ������ ������ ����
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// ���ĵ� �� �迭�� ����
		merge(arr, left, mid, right);
	}
}