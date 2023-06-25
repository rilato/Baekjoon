// 가운데를 기준으로 좌우가 대칭인 수를 팰린드롬수라고 한다.

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num;
	int len = 0;

	while (1) {
		bool check = true;

		cin >> num;

		if (num == "0")
			break;

		len = num.size();

		for (int i = 0; i < len / 2; i++) {
			// 맨 앞쪽부터 차례대로의 숫자와 맨 뒤쪽 숫자부터 차례대로의 숫자 비교
			if (num[i] != num[len - i - 1]) {
				check = false;
				break;
			}
		}

		if (check)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}