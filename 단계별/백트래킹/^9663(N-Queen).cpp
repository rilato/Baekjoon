#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cnt = 0;
int queen[15] = { 0, };

bool check(int num);
void nQueen(int k);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	nQueen(0);
	cout << cnt;
}

bool check(int num) {
	for (int i = 0; i < num; i++) {
		if (queen[i] == queen[num] || abs(queen[num] - queen[i]) == num - i)
			return false;
	}

	return true;
}

void nQueen(int k) {
	if (n == k)
		cnt++;

	else {
		for (int i = 0; i < n; i++) {
			// k는 행, queen[k]는 열
			// 0번째 행부터 시작하되, 열을 하나 하나씩 다 훑는다.
			queen[k] = i;

			// 같은 열에 겹치지 않고, 같은 행에 겹치지 않는다면
			if (check(k))
				// 다음 행을 탐색한다
				nQueen(k + 1);
		}
	}
}