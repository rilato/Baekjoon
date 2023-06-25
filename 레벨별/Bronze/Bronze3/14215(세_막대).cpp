#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 3);

	if (arr[0] + arr[1] > arr[2])
		cout << arr[0] + arr[1] + arr[2];

	// 가장 긴 변의 길이를 a + b - 1로 줄이면 둘레가 최대가 된다.
	else
		cout << (arr[0] + arr[1]) * 2 - 1;

	return 0;
}