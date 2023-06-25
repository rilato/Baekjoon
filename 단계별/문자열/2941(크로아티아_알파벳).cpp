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


// �ٸ� �ڵ�

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
			idx = str.find(croatian[i]);  // �Է¹��� str���� ũ�ξ�Ƽ�� ���ڸ� ã�� �ε����� ��ȯ
			if (idx == string::npos)       // find�� ���� ���� ã�� ���ϴ� ��� string::npos
				break;
			str.replace(idx, croatian[i].length(), "#");  // ũ�ξ�Ƽ�� ���ڸ� ã������ �� �ε����� ���� "#"���� ��ü
		}
	}
	cout << str.length();     // ��ü ���� 
}