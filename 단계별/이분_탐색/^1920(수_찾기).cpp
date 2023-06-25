// binarySearch�� (�迭, �迭�� ũ��, Key)�� ������, �Լ� ������ while���� ���� left�� right�� ���Ͽ� ���� �����Ѵ�.

// sort vs stable_sort �ð����⵵ ==>> https://developer-b.tistory.com/22


// �ð� �ʰ��� �� Ǯ��

// vector�� ����� qsort���� ���ڷ� ������ ������ Ȯ���ϰ�, vector�� ����� qsort���� compare�Լ��� ��� �ۼ��ϴ��� �˾ƾ� �Ѵ�.
// ������ qsort�� ����ϴ�, �־��� ��� �ð����⵵�� N^2�� �����Ƿ�, sort�� ����ϰų� stable_sort�� ����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const void* x, const void* y);
int binarySearch(vector <int> A, int size, int x);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;
	vector <int> A;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}

	qsort(&A[0], A.size(), sizeof(A[0]), compare);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;

		cout << binarySearch(A, A.size(), num) << '\n';
	}
}

int compare(const void* x, const void* y) {
	int a = *(int*)x;
	int b = *(int*)y;

	if (a > b)
		return 1;

	if (a < b)
		return -1;

	return 0;
}

int binarySearch(vector <int> A, int size, int x) {
	int leftIndex = 0;
	int rightIndex = size - 1;
	int mid;

	while (leftIndex <= rightIndex) {
		// �� �Լ��� A�� size�� Ȧ���� ¦���Ŀ� ������� �߾� ���� �������� �׿� ������ return 1�� �ϹǷ�
		// x�� A[mid]�� ũ�ų� ���� ��츸 ���ϸ� �ǰ�, �ε����� 1�� ���ϰų� ���ָ� �ȴ�.
		mid = (leftIndex + rightIndex) / 2;

		if (x == A[mid])
			return 1;

		if (x < A[mid])
			rightIndex = mid - 1;

		if (x > A[mid])
			leftIndex = mid + 1;
	}

	return 0;
}


// ���� Ǯ��
// stable_sort�� ����ϰų�, sort�� ����ؾ� �Ѵ�.
// c++���� ����� ������ ���� �ڵ带 �߰��ϰ�, **�迭�� size�� ���س��� �����Ͽ� �ð� ������ �ذ��Ͽ���.

#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];
int binarySearch(int A[], int size, int x);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;

		cout << binarySearch(A, N, num) << '\n';
	}
}

inline int binarySearch(int A[], int size, int x) {
	int leftIndex = 0;
	int rightIndex = size - 1;
	int mid;

	while (leftIndex <= rightIndex) {
		mid = (leftIndex + rightIndex) / 2;

		if (x == A[mid])
			return 1;

		if (x < A[mid])
			rightIndex = mid - 1;

		if (x > A[mid])
			leftIndex = mid + 1;
	}

	return 0;
}