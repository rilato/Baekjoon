// 틀린 풀이
// 반례가 있는 듯 하다

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	char temp = ' ';
	int cntZero = 0;
	int cntOne = 0;

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (temp != S[i]) {
			if (temp == '1')
				cntOne++;
			else if (temp == '0')
				cntZero++;
		}

		temp = S[i];
	}

	if (cntOne == 0 || cntZero == 0)
		cout << max(cntOne, cntZero);
	else
		cout << min(cntOne, cntZero);
}


// 맞은 풀이

#include <iostream>

using namespace std;

int main() {
	string s;
	int result = 0;

	cin >> s;

	for (int i = 0; i < s.length(); i++)
		if (s[i] != s[i + 1])
			result++;

	if (!result)
		cout << result;
	// 중복된 count를 제거하기 위해 2로 나눈다.
	else
		cout << result / 2;
}