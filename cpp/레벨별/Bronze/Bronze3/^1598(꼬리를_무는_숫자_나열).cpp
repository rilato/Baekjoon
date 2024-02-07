// 틀린 풀이
// 9 12 같은 예외 케이스를 고려하지 않았다

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num1, num2;
	int portion;
	int remain;

	cin >> num1 >> num2;

	portion = (num1 / 4) > (num2 / 4) ? num1 / 4 - num2 / 4 : num2 / 4 - num1 / 4;
	remain = (num1 % 4) > (num2 % 4) ? num1 % 4 - num2 % 4 : num2 % 4 - num1 % 4;

	cout << portion + remain;
}

// 맞은 풀이
// 나머지와 몫에 대해 확실한 처리를 해주었다.

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num1, num2;
	int portion, portion1, portion2;
	int remain, remain1, remain2;

	cin >> num1 >> num2;

	portion1 = (num1 - 1) / 4;
	portion2 = (num2 - 1) / 4;

	remain1 = num1 % 4;
	remain2 = num2 % 4;

	if (remain1 == 0)
		remain1 = 4;

	if (remain2 == 0)
		remain2 = 4;

	portion = portion1 > portion2 ? portion1 - portion2 : portion2 - portion1;
	remain = remain1 > remain2 ? remain1 - remain2 : remain2 - remain1;

	cout << portion + remain;
}