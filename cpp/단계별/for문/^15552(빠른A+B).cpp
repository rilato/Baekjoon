// iostream의 cin과 cout은 stdio.h의 scanf와 printf에 비해 속도가 느리다.
// C++은 C++과 C의 표준 스트림 내용을 동기화하고 있기 때문이다.
// ios_base::sync_with_stdio(false); 와 cin.tie(NULL);을 추가하여 속도를 향상시킬 수 있다.

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, A, B;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
}