#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	// 숫자 N을 1로 만들기 위해 필요한 연산 횟수 저장
	arr[0] = 0;
	arr[1] = 0;

	//arr[i] = arr[i - 1] + 1	// 현재 보고 있는 숫자 : i , 바로 이전 숫자 : i - 1 , 연산 횟수 1 증가 : + 1
	//arr[i] = arr[i / 2] + 1	// 현재 보고 있는 숫자 : i , 바로 이전 숫자 : i / 2 , 연산 횟수 1 증가 : + 1
	//arr[i] = arr[i / 3] + 1	// 현재 보고 있는 숫자 : i , 바로 이전 숫자 : i / 3 , 연산 횟수 1 증가 : + 1

	for (int i = 2; i <= N; i++) {
		// 1 빼기는 모든 숫자 N에 대해 적용 가능하므로, 일단 모든 arr[i]는 빼기 1이 기준 점임.
		arr[i] = arr[i - 1] + 1;
		// 2로 나누어 떨어지면, 1 빼기와 2 나누기 중, 더 효율적인 계산 결과를 저장
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		// 3으로 나누어 떨어지면, 1 빼기와 2 나누기 중, 더 효율적인 계산 결과를 저장
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
	}

	cout << arr[N] << '\n';

	return 0;
}
