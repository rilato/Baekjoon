#include <iostream>
#include <string>

using namespace std;

bool isGroupWord(string s);

int main()
{
	int num;
	string s;
	int count = 0;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> s;
		if (isGroupWord(s))
			++count;
	}

	cout << count;
}

bool isGroupWord(string s) {
	int arr[26] = { 0, };

	for (int i = 0; i < s.size(); i++) {	// 연속으로 나열된 단어를 한개로 줄이는 작업 ex) happpy -> hapy
		if (s[i] == s[i + 1]) {
			s.erase(i + 1, 1);
			i--;
		}
	}

	for (int i = 0; i < s.size(); i++)
		++arr[s[i] - 'a'];

	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 2)	// 그룹 단어가 아닌 경우에 해당
			return false;
		else
			continue;
	}

	return true;
}