// 원래 기수 정렬이라 함은 자릿수끼리 비교하는 정렬 방식이다.
// 이 문제에서는 일반적인 소트가 아닌, 주어진 숫자를 배열의 인덱스로 활용하여 소트를 한다.

#include <iostream>

using namespace std;

int N, num;
int arr[10001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		arr[num]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}