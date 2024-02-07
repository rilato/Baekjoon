#include <iostream>
#include <string>

using namespace std;

int selfNumber(int num);

int main()
{
	int ans;
	int arr[10100] = { 0, };	// 9999의 경우 9999 + 9 + 9 + 9 + 9 해서 10000이 넘어가므로, 10000보다 큰 배열을 만들어줘야 함

	for (int i = 1; i <= 10000; i++) {
		ans = selfNumber(i);
		++arr[ans];
	}

	for (int i = 1; i <= 10000; i++) {	// 10000까지만 출력해야하므로 10000을 제한으로 둠
		if (arr[i] == 0)
			cout << i << '\n';
	}
}

int selfNumber(int num)	// self number를 확인
{
	string changeNum;
	string character;
	int sum = 0;

	changeNum = to_string(num);

	for (int i = 0; i < changeNum.size(); i++) {
		character = changeNum.substr(i, 1);
		sum += stoi(character);
	}

	sum += num;

	return sum;
}



// 문자로 바꾸지 않고 숫자로 해결하기 위해서는 아래와 같이 작성할 수도 있다.
// int selfNumber(int i) {
//	int res = i;
//	if (i >= 10000) { res += i / 10000; i %= 10000; }
//	if (i >= 1000) { res += i / 1000; i %= 1000; }
//	if (i >= 100) { res += i / 100; i %= 100; }
//	if (i >= 10) { res += i / 10; i %= 10; }
//	return res += i;
//}