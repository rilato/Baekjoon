//자료구조 교재 참고
//1. 작은 원반 n - 1개를 A에서 B로 이동
//2. 큰 원반 1개를 A에서 C로 이동
//3. 작은 원반 n - 1개를 B에서 C로 이동

//원반 n개를 이동하는 문제는 원반 n - 1개를 이동하는 문제로 세분화되고, 또 n - 1개를 이동하는 문제는 원반 n - 2개를 이동하는 문제로 세분화된다.
//즉 원반 n개를 이동하는 문제는 결국 원반 1개를 이동하는 문제로 세분화되는 것이다.


#include <iostream>
#include <cmath>

using namespace std;

void hanoiTower(int num, int from, int by, int to);
//num개의 원반을 by를 거쳐서(이용해서) from에서 to로 이동한다

int main() {
	int num;

	cin >> num;

	cout << (int)pow(2, num) - 1 << '\n';	//기본적으로 pow함수는 double 형식을 반환한다.
	//여기서 pow 함수 앞에 (int)를 적지 않으면, 입력 최대가 20인 pow 함수의 특성상 오차가 커져서 '틀렸습니다.'가 뜬다!

	hanoiTower(num, 1, 2, 3);
}

void hanoiTower(int num, int from, int by, int to) {
	if (num == 1) {
		cout << from << ' ' << to << '\n';
	}	//가장 마지막에 남는 원반은 가장 작은, 맨 위에 위치한 원반이므로 원반 1이 된다.

	else {
		hanoiTower(num - 1, from, to, by);	//1. 작은 원반 n - 1개를 A에서 B로 이동 / 인자 to가 매개변수 by로, 인자 by가 매개변수 to로 들어갔는데,
		//그 이유는 원반 n개를 A에서 C로 이동하기 위해서는 먼저 n - 1개의 원반을 A에서 B로 이동해야하기 때문이다.
		cout << from << ' ' << to << '\n';//2. 큰 원반 1개를 A에서 C로 이동
		hanoiTower(num - 1, by, from, to);//3. 작은 원반 n - 1개를 B에서 C로 이동
	}
}