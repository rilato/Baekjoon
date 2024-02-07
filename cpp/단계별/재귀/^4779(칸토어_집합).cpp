// 재귀의 형식을 익힌다.
// cmath를 추가하지 않으면 pow를 인식하지 못한다.

#include <iostream>
#include <cmath>

using namespace std;

int N;
void recursive(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> N) {
		recursive(N);
		cout << '\n';
	}

	return 0;
}

void recursive(int n) {
	if (!n) {
		cout << "-";
		return;
	}

	recursive(n - 1);

	for (int i = 0; i < pow(3, n - 1); i++) {
		cout << " ";
	}

	recursive(n - 1);
}