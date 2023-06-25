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

	// size를 고정시켜놔야지 나중에 s.erase했을 때 size에 변화 없이 for문을 돌릴 수 있음!
	int len = s.size();

	vector <string> v(len);

	for (int i = 0; i < len; i++) {
		v[i] = s;	// v.push_back(s)는 인식 못함!

		s.erase(s.begin());
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < len; i++) {
		cout << v[i] << '\n';
	}
}