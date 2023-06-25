/* 주의사항 */

// 산술평균에서 (0 + 0 + (-1)) / 3 = -0.333333... 이고 이를 첫째 자리에서 반올림하면 0이다. - 0으로 출력하면 안된다!!

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num, maxIndex;
	double average;
	int sum = 0;
	int max = 0;
	int cnt = 0;
	int count[8001] = { 0, };

	cin >> input;

	int* arr = new int[input];

	// 사용자에게 input만큼 num값을 입력받는데, num 위치에 해당하는 배열 값을 1씩 증가시킨다.
	// 이렇게 되면 해당 배열의 값과 인덱스 값을 통해 어떠한 수가 얼마나 입력되었는지 알 수 있다.
	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[i] = num;
		++count[num + 4000];
	}

	sort(arr, arr + input);

	//산술 평균
	for (int i = 0; i < input; i++)
		sum += arr[i];

	average = (double)sum / input;

	//(0 + 0 + (-1)) / 3 = -0.333333... 이고 이를 첫째 자리에서 반올림하면 0이다. - 0으로 출력하면 안된다.
	if (round(average) == 0)
		cout << 0 << '\n';
	else
		cout << round(average) << '\n';

	//중앙값
	cout << arr[input / 2] << '\n';

	//최빈값
	for (int i = 0; i < 8001; i++) {
		if (count[i] > max)
			max = count[i];
	}

	for (int i = 0; i < 8001; i++) {
		if (max == count[i]) {
			++cnt;
			maxIndex = i;
		}
	}

	if (cnt == 1)
		cout << maxIndex - 4000 << '\n';

	if (cnt >= 2) {
		cnt = 0;
		int i = 0;

		while (1) {
			if (cnt == 2)
				break;

			if (count[i] == max) {
				maxIndex = i;
				++cnt;
			}

			++i;
		}

		cout << maxIndex - 4000 << '\n';
	}

	//범위 (최대값 - 최소값)
	cout << arr[input - 1] - arr[0];

	delete[] arr;
}



// 다른 코드. 최빈값을 좀더 효율적으로 구한 코드
// 최빈값이 여러 개인 경우, 두 번째로 작은 값을 구해야하므로, 단 두 번의 검사로 걸러낼 수 있는 bool을 사용한다.

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num, maxIndex;
	double average;
	int sum = 0;
	int max = 0;
	bool flag = false;
	int count[8001] = { 0, };

	cin >> input;

	int* arr = new int[input];

	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[i] = num;
		++count[num + 4000];

		// max값을 구할 때 여기에 넣을 수 있다. 즉 for문 사용을 1회 줄일 수 있다.
		if (count[num + 4000] >= max)
			max = count[num + 4000];
	}

	sort(arr, arr + input);

	//산술 평균
	for (int i = 0; i < input; i++)
		sum += arr[i];

	average = (double)sum / input;

	//(0 + 0 + (-1)) / 3 = -0.333333... 이고 이를 첫째 자리에서 반올림하면 0이다. - 0으로 출력하면 안된다.
	if (round(average) == 0)
		cout << 0 << '\n';
	else
		cout << round(average) << '\n';

	//중앙값
	cout << arr[input / 2] << '\n';

	//최빈값

	for (int i = 0; i < 8001; i++) {
		if (count[i] == max) {
			maxIndex = i;

			if (flag)
				break;

			flag = true;
		}
	}

	cout << maxIndex - 4000 << '\n';

	//범위 (최대값 - 최소값)
	cout << arr[input - 1] - arr[0];

	delete[] arr;
}