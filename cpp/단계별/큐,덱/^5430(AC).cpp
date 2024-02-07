// ������ ���� �����ų� �������� �ʾ�����, ����� �����ų� ������ ��ó�� ���̰� �����ν� ������ ����Ѵ�.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void inputNumber(string arr, vector<int>& v, bool& isEmpty);
void functionR(bool& flag, int& size, bool& isEmpty);
void functionD(bool& flag, bool& isError, bool& isEmpty, int& startIndex, int& endIndex, int& size);
void print(vector<int> v, int startIndex, int endIndex, bool flag, bool isEmpty, bool isError);

int main()
{
	int testCase, num;
	string commands, arr;
	char command;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		bool flag = true;	// true�� ������
		bool isError = false;
		bool isEmpty = false;
		vector <int> v;

		cin >> commands >> num >> arr;

		int size = num;
		int startIndex = 0;
		int endIndex = num - 1;

		inputNumber(arr, v, isEmpty);

		for (int j = 0; j < commands.size(); j++) {
			command = commands[j];

			if (command == 'R')
				functionR(flag, size, isEmpty);

			if (command == 'D')
				functionD(flag, isError, isEmpty, startIndex, endIndex, size);
		}

		print(v, startIndex, endIndex, flag, isEmpty, isError);
	}
}

void inputNumber(string arr, vector<int>& v, bool& isEmpty) {
	string number = "";

	for (int j = 0; j < arr.size(); j++) {
		if (arr[j] == '[' || arr[j] == ',' || arr[j] == ']')
			continue;

		while (1) {
			if (arr[j] == ',' || arr[j] == ']') {
				j--;
				break;
			}

			number += arr[j++];
		}

		v.push_back(stoi(number));

		number = "";
	}

	if (v.empty())
		isEmpty = true;
}

void functionR(bool& flag, int& size, bool& isEmpty) {
	// size�� 0�� ���
	if (!size)
		isEmpty = true;

	if (flag) {
		flag = false;
		return;
	}

	if (!flag) {
		flag = true;
		return;
	}
}

void functionD(bool& flag, bool& isError, bool& isEmpty, int& startIndex, int& endIndex, int& size) {
	--size;

	if (size < 0) {
		isError = true;
		return;
	}

	if (size == 0) {
		isEmpty = true;
	}

	if (flag)
		++startIndex;

	if (!flag)
		--endIndex;
}

void print(vector<int> v, int startIndex, int endIndex, bool flag, bool isEmpty, bool isError) {
	if (isError) {
		cout << "error\n";
		return;
	}

	if (isEmpty) {
		cout << "[]\n";
		return;
	}

	cout << '[';

	if (flag) {
		for (int i = startIndex; i < endIndex; i++)
			cout << v[i] << ',';
		cout << v[endIndex] << "]\n";
	}

	else {
		for (int i = endIndex; i > startIndex; i--)
			cout << v[i] << ',';
		cout << v[startIndex] << "]\n";
	}
}

// 1 RD 0 [] or 1 RD 1 [10] �ݷ� ������ ����ؼ� Ʋ�ȴٰ� �Ѵ�.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int testCase, num;
	string commands, arr;
	char command;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		bool flag = true;

		cin >> commands;
		cin >> num;
		cin >> arr;

		int startIndex = 0;
		int endIndex = num - 1;

		vector <int> v;

		for (int j = 0; j < arr.size(); j++) {
			string myString;

			if (arr[j] == '[' || arr[j] == ']' || arr[j] == ',')
				continue;

			// ���ڸ� ������ �޾��ֱ� ���� while���̴�.
			while (1) {
				if (arr[j] == ']' || arr[j] == ',')
					break;

				myString += arr[j++];
			}

			v.push_back(stoi(myString));
		}

		for (int j = 0; j < commands.size(); j++) {
			command = commands[j];

			if (command == 'R') {
				if (v.empty())
					break;

				// flag�� true�̸� R�� �� ���̳� ������ �Ŀ��� ���������� �ǹ��Ѵ�.
				if (flag == true)
					flag = false;

				// flag�� false�̸� R�� �� ���̳� ������ �� ���������� �ǹ��Ѵ�.
				else
					flag = true;
			}

			if (command == 'D') {
				// ���Ͱ� ����ִٸ�, startIndex�� �ϳ� ���Ѵ�.
				if (v.empty()) {
					++startIndex;
					break;
				}

				else {
					// �������� ��� �� ���� �����ش�.
					if (flag == true)
						++startIndex;

					// �������� ��� �� �ڸ� �����ش�.
					if (flag == false)
						--endIndex;
				}
			}
		}

		// 1 RD 1 [100]�� �־��� �� ���ϴ� ��� ���� ������ �ʾҴ�.
		// �̸� �ذ��ϱ� ���� startIndex - endIndex == 1�� �߰��ߴ�.
		// v.empty()�� ��쵵 �̿� �ش��Ѵ�.
		if (startIndex - endIndex == 1) {
			cout << "[]\n";
			continue;
		}

		// ���Ͱ� ����ִ� ��츦 �����ϰ�, startIndex�� ���� endIndex���� �۰ų� ���ƾ��Ѵ�.
		// startIndex�� �� ũ�ٴ� ���� ������ �߻������� �ǹ��Ѵ�.
		if (startIndex > endIndex) {
			cout << "error\n";
			continue;
		}

		if (!v.empty()) {
			cout << '[';

			// �������� ���
			if (flag == true) {
				for (int j = startIndex; j < endIndex; j++)
					cout << v[j] << ',';

				cout << v[endIndex] << "]\n";
			}

			// �������� ���
			if (flag == false) {
				for (int j = endIndex; j > startIndex; j--)
					cout << v[j] << ',';

				cout << v[startIndex] << "]\n";
			}
		}
	}
}

// ���ô� �� ���ư�����, 1 R 0 []�� �־��� �� ��Ÿ�� ������ �߻��ߴ�. (Out of Bounds)
// dq�� ����� ��, R Case�� ����� �۵����� �ʾ� ��Ÿ�� ������ �߻��ߴ�.

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	int testCase, num;
	string commands, arr;
	char command;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> commands;
		cin >> num;
		cin >> arr;

		deque <int> dq;

		for (int j = 0; j < arr.size(); j++) {
			string myString;

			if (arr[j] == '[' || arr[j] == ']' || arr[j] == ',')
				continue;

			while (1) {
				if (arr[j] == ']' || arr[j] == ',')
					break;

				myString += arr[j++];
			}

			dq.push_back(stoi(myString));	// string type�� int type���� �ٲ�� �Ѵ�.
		}

		for (int j = 0; j < commands.size(); j++) {
			command = commands[j];

			if (command == 'R') {
				for (int k = 0; k < dq.size() / 2; k++) {
					int temp = dq[k];
					dq[k] = dq[dq.size() - k - 1];		// v.size()�� 4��� �ϸ�, ������ �ε����� '3' �̴�!!
					dq[dq.size() - k - 1] = temp;
				}
			}

			if (command == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					break;
				}

				else
					dq.pop_front();
			}
		}

		if (command == 'D' && dq.empty())
			continue;

		cout << '[';
		for (int j = 0; j < dq.size() - 1; j++)
			cout << dq[j] << ',';
		cout << dq.back() << ']' << '\n';
	}
}