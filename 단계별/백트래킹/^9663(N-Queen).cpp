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
			// k�� ��, queen[k]�� ��
			// 0��° ����� �����ϵ�, ���� �ϳ� �ϳ��� �� �ȴ´�.
			queen[k] = i;

			// ���� ���� ��ġ�� �ʰ�, ���� �࿡ ��ġ�� �ʴ´ٸ�
			if (check(k))
				// ���� ���� Ž���Ѵ�
				nQueen(k + 1);
		}
	}
}