// 어차피 3의 배수이고, 0이 포함되어있다면, 내림차순으로 정렬한 수가 가장 큰 수가 된다.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	long long sum = 0;
	bool check = false;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			check = true;
		sum += s[i] - '0';
	}

	// 모든 자리수의 합이 3의 배수가 아니라면
	if (sum % 3)
		check = false;

	if (!check) {
		cout << -1;
		return 0;
	}

	// 3의 배수이고, 0이 포함되어있다면, 내림차순으로 정렬한 수가 가장 큰 수가 된다.
	sort(s.begin(), s.end(), greater<>());

	cout << s;
}