//이 문제를 풀기 위해선 EOF(End Of File)에 대해 알 필요가 있다.
//EOF(End Of File)은 파일의 끝을 알리는 함수로 - 1의 값을 가지며, 콘솔 창에서는 Ctrl + Z가 EOF를 의미한다.
//C++에서는 cin.eof()함수가 bool타입을 가지며 EOF를 읽으면 true값으로 바뀌게 된다.

#include <iostream>

using namespace std;

int main()
{
	int A, B;

	while (1) {
		cin >> A >> B;

		if (cin.eof() == 1) // EOF가 참이면 탈출
			break;

		cout << A + B << '\n';
	}
}



// 다른 방법

#include <iostream>

using namespace std;

int main()
{
	int A, B;

	while (cin >> A >> B) {
		cout << A + B << '\n';
	}
}