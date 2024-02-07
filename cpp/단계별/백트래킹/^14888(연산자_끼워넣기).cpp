// https://cryptosalamander.tistory.com/60

#include <iostream>

using namespace std;

int N;
int arr[11] = { 0, };
int op[4] = { 0, };
int maxNum = -1000000000;
int minNum = 1000000000;

void bt(int result, int index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	bt(arr[0], 1);

	cout << maxNum << '\n' << minNum;
}

void bt(int result, int index) {
	// index == N이라는 것은 맨 끝까지 와서 더이상 계산할 피연산자가 없음을 의미한다.
	if (index == N) {
		if (result >= maxNum)
			maxNum = result;
		if (result <= minNum)
			minNum = result;
		return;
	}

	// for문을 통해 깊이를 더 깊게 파고 들어간다.
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			// 연산자 한 개를 사용했으므로, 1을 줄여준다.
			op[i]--;

			// 알맞은 연산을 해줌과 동시에, 다음 숫자를 가리키도록 index를 증가시킨다.
			// ++index나 index++을 하면 원하는 결과가 나오지 않는다.
			if (i == 0)
				bt(result + arr[index], index + 1);
			// else if가 아닌 if를 사용하면 원하는 결과가 나오지 않는다.
			// 맨 밑의 else로 빠져버리기 때문이다.
			// 그냥 if만 사용할 거면 맨 밑도 if (i == 3)으로 처리한다.
			if (i == 1)
				bt(result - arr[index], index + 1);
			if (i == 2)
				bt(result * arr[index], index + 1);
			if (i == 3)
				bt(result / arr[index], index + 1);

			// 이번에는 다른 연산자를 사용할 것이므로, 아까 사용했던 연산자를 다시 복원한다.
			op[i]++;
		}
	}
}