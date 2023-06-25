// 시간 초과가 난 풀이
// binarySearch함수의 while문 내부에서 for문을 한번 더 돌림으로써 시간이 길어지는 듯하다. 

#include <iostream>
#include <algorithm>

using namespace std;

void binarySearch(int size, int num);

int N[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputN, inputM, num;

	cin >> inputN;

	for (int i = 0; i < inputN; i++)
		cin >> N[i];

	stable_sort(N, N + inputN);

	cin >> inputM;

	for (int i = 0; i < inputM; i++) {
		cin >> num;

		binarySearch(inputN, num);
	}
}

void binarySearch(int size, int num) {
	int leftIndex = 0;
	int rightIndex = size - 1;
	int count = 0;

	while (leftIndex <= rightIndex) {
		int midIndex = (leftIndex + rightIndex) / 2;

		if (num == N[midIndex]) {
			for (int i = leftIndex; i <= rightIndex; i++)
				if (num == N[i])
					++count;
			break;
		}

		if (num < N[midIndex])
			rightIndex = midIndex - 1;

		if (num > N[midIndex])
			leftIndex = midIndex + 1;
	}

	cout << count << ' ';
}


// 정상적인 풀이

// 이진 탐색으로 구현된 함수인 upper_bound와 lower_bound를 활용한다.

// 정렬된 배열에서 특정 값과 크거나 같은 인덱스를 반환하는 lower_bound함수와
// 특정 값 보다 큰 인덱스를 반환하는 upper_bound 함수의 차를 이용하여 같은 숫자의 개수를 센다.

#include <iostream>
#include <algorithm>

using namespace std;

int N[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputN, inputM, num;

	cin >> inputN;

	for (int i = 0; i < inputN; i++) {
		cin >> N[i];
	}

	sort(N, N + inputN);

	cin >> inputM;

	for (int i = 0; i < inputM; i++) {
		cin >> num;

		cout << upper_bound(N, N + inputN, num) - lower_bound(N, N + inputN, num) << ' ';
	}
}