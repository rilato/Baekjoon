// 666이 포함된 숫자를 "찾아야"하므로, find() 함수를 쓰고, 666을 문자열로 만든뒤 "666"을 찾는다.
// find()함수가 문자열을 찾지 못한 경우, string::npos를 반환하는데, 이 값은 -1을 가리킨다.

#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;
	int count = 0;
	int six = 666;

	cin >> num;

	while (1) {
		string stringSix = to_string(six);

		// 666이라는 문자열이 포함되있는 경우 find 함수는 0, 1, 2... 등의 숫자를 반환한다.
		// 666이라는 문자열이 포함되어있지 않은 경우 find 함수는 string::npos (-1)을 반환한다.
		if (stringSix.find("666") != -1)
			++count;

		if (count == num)
			break;

		six += 1;
	}

	cout << six;
}