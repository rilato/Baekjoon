// 실제로 값을 뒤집거나 삭제하지 않았지만, 출력을 뒤집거나 삭제한 것처럼 보이게 함으로써 정답을 출력한다.

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
		bool flag = true;	// true면 정방향
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
	// size가 0인 경우
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

// 1 RD 0 [] or 1 RD 1 [10] 반례 때문에 계속해서 틀렸다고 한다.

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

			// 숫자를 온전히 받아주기 위한 while문이다.
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

				// flag가 true이면 R을 몇 번이나 진행한 후에도 정방향임을 의미한다.
				if (flag == true)
					flag = false;

				// flag가 false이면 R을 몇 번이나 진행한 후 역방향임을 의미한다.
				else
					flag = true;
			}

			if (command == 'D') {
				// 벡터가 비어있다면, startIndex를 하나 더한다.
				if (v.empty()) {
					++startIndex;
					break;
				}

				else {
					// 정방향인 경우 맨 앞을 가려준다.
					if (flag == true)
						++startIndex;

					// 역방향인 경우 맨 뒤를 가려준다.
					if (flag == false)
						--endIndex;
				}
			}
		}

		// 1 RD 1 [100]을 넣었을 때 원하는 출력 값이 나오지 않았다.
		// 이를 해결하기 위해 startIndex - endIndex == 1를 추가했다.
		// v.empty()인 경우도 이에 해당한다.
		if (startIndex - endIndex == 1) {
			cout << "[]\n";
			continue;
		}

		// 벡터가 비어있는 경우를 제외하고, startIndex는 원래 endIndex보다 작거나 같아야한다.
		// startIndex가 더 크다는 것은 에러가 발생했음을 의미한다.
		if (startIndex > endIndex) {
			cout << "error\n";
			continue;
		}

		if (!v.empty()) {
			cout << '[';

			// 정방향인 경우
			if (flag == true) {
				for (int j = startIndex; j < endIndex; j++)
					cout << v[j] << ',';

				cout << v[endIndex] << "]\n";
			}

			// 역방향인 경우
			if (flag == false) {
				for (int j = endIndex; j > startIndex; j--)
					cout << v[j] << ',';

				cout << v[startIndex] << "]\n";
			}
		}
	}
}

// 예시는 잘 돌아가지만, 1 R 0 []를 넣었을 때 런타임 에러가 발생했다. (Out of Bounds)
// dq가 비었을 때, R Case가 제대로 작동하지 않아 런타임 에러가 발생했다.

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

			dq.push_back(stoi(myString));	// string type을 int type으로 바꿔야 한다.
		}

		for (int j = 0; j < commands.size(); j++) {
			command = commands[j];

			if (command == 'R') {
				for (int k = 0; k < dq.size() / 2; k++) {
					int temp = dq[k];
					dq[k] = dq[dq.size() - k - 1];		// v.size()가 4라고 하면, 마지막 인덱스는 '3' 이다!!
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