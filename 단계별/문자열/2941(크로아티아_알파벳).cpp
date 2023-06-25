#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	int count = 0;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (isalpha(input[i]))
			++count;
		if (input[i] == 'd' && input[i + 1] == 'z' && input[i + 2] == '=')
			--count;
		if (input[i] == 'l' && input[i + 1] == 'j')
			--count;
		if (input[i] == 'n' && input[i + 1] == 'j')
			--count;
	}

	cout << count;
}


// 다른 코드

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int idx;
	string str;

	cin >> str;
	for (int i = 0; i < croatian.size(); i++)
	{
		while (1) {
			idx = str.find(croatian[i]);  // 입력받은 str에서 크로아티아 문자를 찾아 인덱스를 반환
			if (idx == string::npos)       // find를 통해 값을 찾지 못하는 경우 string::npos
				break;
			str.replace(idx, croatian[i].length(), "#");  // 크로아티아 문자를 찾았으면 그 인덱스를 문자 "#"으로 대체
		}
	}
	cout << str.length();     // 전체 길이 
}