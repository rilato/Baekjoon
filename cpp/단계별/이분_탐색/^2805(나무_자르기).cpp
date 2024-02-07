// 시간 초과가 난 풀이
// 이분 탐색을 바탕으로 하는 upper_bound를 사용했지만,
// for문을 통해 큰 값부터 1개씩 줄여나가므로, worst case에서 시간이 오래 소요될 수 있다.

// 가장 중요한 sum의 자료형이 int가 아닌 long long이다!!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// inputN은 나무의 수
	// inputM은 가져가려고 하는 나무의 길이
	int inputN, inputM, num;
	vector <int> v;

	cin >> inputN >> inputM;

	for (int i = 0; i < inputN; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	// 배열의 요소 중 가장 큰 값부터 하나씩 줄여가면서 나무를 잘랐을 때 길이의 합을 구한다.
	int max = v.back();

	while (1) {
		int sum = 0;
		// index는 max값 보다 큰 값을 갖는 배열 요소의 index를 나타낸다.
		int index = upper_bound(v.begin(), v.end(), max) - v.begin();

		for (int i = index; i < inputN; i++)
			sum += v[i] - max;

		if (inputM <= sum)
			break;

		--max;
	}

	cout << max;
}



// 배열을 사용한 정답
// ans를 이용하지 않고 right을 이용해 값을 출력

// 아주 큰 두 수의 합은 int의 범위를 벗어날 수 있으므로, 자료형을 long long으로 설정한다.

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// inputN은 나무의 수
	// inputM은 가져가려고 하는 나무의 길이
	long long inputN, inputM, num;
	long long max = 0;

	cin >> inputN >> inputM;

	for (int i = 0; i < inputN; i++) {
		cin >> num;
		arr[i] = num;

		// vector에 넣는 값 중 가장 큰 값을 max에 저장한다.
		if (num > max)
			max = num;
	}

	long long left = 0;
	long long right = max;
	long long mid = 0;

	// 정렬을 따로 하지 않으므로 소요시간을 줄인다.

	while (left <= right) {
		long long sum = 0;

		mid = (left + right) / 2;

		for (int i = 0; i < inputN; i++) {
			if (mid < arr[i])
				sum += arr[i] - mid;
		}

		if (sum >= inputM) {
			left = mid + 1;
		}

		else {
			right = mid - 1;
		}
	}

	// while문은 마지막 순간(left > right)까지 탐색을 하므로, 빠져나올 때 right값이 곧 정답이 된다.
	cout << right;
}


// vector를 사용한 정답
// answer에 값을 저장하고 이를 출력

// 아주 큰 두 수의 합은 int의 범위를 벗어날 수 있으므로, 자료형을 long long으로 설정한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// inputN은 나무의 수
	// inputM은 가져가려고 하는 나무의 길이
	int inputN, inputM, num;
	int max = 0;
	vector <int> v;

	cin >> inputN >> inputM;

	for (int i = 0; i < inputN; i++) {
		cin >> num;
		v.push_back(num);

		if (num > max)
			max = num;
	}

	long long left = 1;
	long long right = max;
	long long mid = 0;
	long long answer = 0;

	// 정렬을 따로 하지 않으므로 소요시간을 줄인다.

	while (left <= right) {
		long long sum = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < inputN; i++) {
			if (mid < v[i])
				sum += v[i] - mid;
		}

		if (inputM <= sum) {
			// 빠져 나갈 경우에, mid + 1을 하기 전의 mid 값을 answer에 저장한다.
			answer = mid;
			left = mid + 1;
		}

		else {
			right = mid - 1;
		}
	}

	cout << answer;
}