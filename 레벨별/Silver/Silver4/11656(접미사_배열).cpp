#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	cin >> s;

	// size�� �������ѳ����� ���߿� s.erase���� �� size�� ��ȭ ���� for���� ���� �� ����!
	int len = s.size();

	vector <string> v(len);

	for (int i = 0; i < len; i++) {
		v[i] = s;	// v.push_back(s)�� �ν� ����!

		s.erase(s.begin());
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < len; i++) {
		cout << v[i] << '\n';
	}
}