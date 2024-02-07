// binarySearch는 (배열, 배열의 크기, Key)를 보내고, 함수 내에서 while문을 통해 left와 right을 비교하여 값을 결정한다.

// sort vs stable_sort 시간복잡도 ==>> https://developer-b.tistory.com/22


// 시간 초과가 난 풀이

// vector를 사용한 qsort에서 인자로 무엇이 들어가는지 확인하고, vector를 사용한 qsort에서 compare함수를 어떻게 작성하는지 알아야 한다.
// 하지만 qsort를 사용하니, 최악의 경우 시간복잡도가 N^2이 나오므로, sort를 사용하거나 stable_sort를 사용한다.

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
		// 이 함수는 A의 size가 홀수냐 짝수냐와 관계없이 중앙 값을 기준으로 그와 같으면 return 1을 하므로
		// x와 A[mid]는 크거나 작은 경우만 비교하면 되고, 인덱스도 1을 더하거나 빼주면 된다.
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


// 맞은 풀이
// stable_sort를 사용하거나, sort를 사용해야 한다.
// c++과의 입출력 연결을 끊는 코드를 추가하고, **배열의 size를 정해놓고 시작하여 시간 문제를 해결하였다.

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