// 입력을 했는데, cnt가 나오지 않는다.
// 어떻게 해야 할까?

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int cnt = 0;

	while (getline(cin, s)) {
		cnt++;
	}

	cout << cnt;
}