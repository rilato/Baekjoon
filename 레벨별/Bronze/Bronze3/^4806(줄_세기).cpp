// �Է��� �ߴµ�, cnt�� ������ �ʴ´�.
// ��� �ؾ� �ұ�?

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