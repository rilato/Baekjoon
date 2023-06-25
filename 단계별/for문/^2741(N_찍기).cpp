// ios_base::sync_with_stdio(false); / cin.tie(NULL);를 추가하면 4ms의 시간 이득을 볼 수 있다.
// 하지만 가장 중요한 것은 endl을 쓰지 않고 "\n"을 써주는 것이 획기적인 속도 향상에 도움이 된다는 것이다.


// 8ms
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, i;

	cin >> N;

	for (i = 1; i < N; i++) {
		cout << i << "\n";
	}
	cout << i;
}



// 12ms
#include <iostream>

using namespace std;

int main()
{
	int N, i;

	cin >> N;

	for (i = 1; i < N; i++) {
		cout << i << "\n";
	}
	cout << i;
}