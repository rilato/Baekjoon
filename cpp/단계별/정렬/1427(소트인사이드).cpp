#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	string stringNum;

	cin >> num;

	stringNum = to_string(num);

	int* arr = new int[stringNum.size()];

	for (int i = 0; i < stringNum.size(); i++)
		arr[i] = stoi(stringNum.substr(i, 1));

	sort(arr, arr + stringNum.size(), greater <int>());

	for (int i = 0; i < stringNum.size(); i++)
		cout << arr[i];

	delete[] arr;
}



// 다른 풀이

// 숫자를 입력하지만, int type이어야 한다는 말이 없으므로, 문자열 그대로 처리한다.

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	cin >> str;
	sort(str.begin(), str.end(), greater<char>());
	cout << str;
}