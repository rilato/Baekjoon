// 이분 탐색을 수행하기 위해 중간 지점을 찾는 과정에서 두 수를 더하는 순간, 범위를 벗어나는 경우가 생긴다.
// 따라서 long long 으로 선언해줘야 한다.

// 최소 값을 기준으로 탐색을 하면 안된다.
// 최소 값이 필요 없는 경우가 있기 때문이다.

// 2 10
// 2
// 100
// => 10cm로 10개가 필요하다.
// 최소값인 2로 결정할 수 없다.

// 시간 초과가 난 풀이

#include <iostream>

using namespace std;

int K[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputK, inputN;
	int count = 0;
	int breakCount = 0;
	int min = 1000000;

	cin >> inputK >> inputN;

	for (int i = 0; i < inputK; i++) {
		cin >> K[i];

		if (K[i] < min)
			min = K[i];
	}

	int left = 0;
	int right = min;
	// 가장 작은 숫자의 길이를 기준으로, 나머지 길이들을 몇 개로 자를 수 있는지 확인한다.
	int mid = min;
	int max = 0;

	while (1) {
		// 탈출 조건
		if (breakCount < inputN && inputN <= count)
			break;

		count = 0;
		breakCount = 0;
		max = mid;

		for (int i = 0; i < inputK; i++) {
			// 가장 작은 숫자의 길이를 기준으로, 나머지 길이들을 몇 개로 자를 수 있는지 확인한다.
			count += (K[i] / mid);

			// test값으로 넣은 mid보다 1만큼 큰 수를 넣어서, 몇 개로 자를 수 있는지 확인한다.
			// 만약 count = 11인데, breakCount = 10이라면 탈출한다.
			breakCount += (K[i] / (mid + 1));
		}

		// count가 inputN보다 크다는 것은 케이블을 더 긴 길이로 잘라도 된다는 것을 의미한다.
		// count와 inputN이 같아도, 더 길게 자를 수 있는지 확인해봐야 하므로 조건에 = 도 추가한다.
		if (count >= inputN) {
			left = mid + 1;
		}

		if (count < inputN) {
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}

	cout << max;
}



// 맞은 풀이

#include <iostream>

using namespace std;

long long K[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputK, inputN;
	// 1cm의 단위로 자른다면, count가 21억을 초과하는 수가 등장할 수 있으므로, 자료형은 long long이다.
	long long count = 0;
	long long max = 0;

	cin >> inputK >> inputN;

	for (int i = 0; i < inputK; i++) {
		cin >> K[i];

		if (K[i] > max)
			max = K[i];
	}

	// 자르는 길이는 0이어서는 안된다.
	// 따라서 left는 1로 설정한다.
	long long left = 1;
	long long right = max;
	// 가장 큰 숫자의 길이를 기준으로, 일단 mid 값을 설정한다.
	long long mid = max;

	while (left <= right) {
		count = 0;

		for (int i = 0; i < inputK; i++) {
			// 중간 값 길이를 기준으로, 나머지 길이들을 몇 개로 자를 수 있는지 확인한다.
			count += (K[i] / mid);
		}

		// count가 inputN보다 크다는 것은 케이블을 더 긴 길이로 잘라도 된다는 것을 의미한다.
		// count와 inputN이 같아도, 더 길게 자를 수 있는지 확인해봐야 하므로 조건에 = 도 추가한다.
		if (count >= inputN) {
			left = mid + 1;
		}

		if (count < inputN) {
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}

	cout << mid;
}