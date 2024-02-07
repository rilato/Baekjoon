// k 층의 n 호는 k - 1 층의 1호부터 n 호까지 사는 사람의 수를 합한 것인데
// 이는 k - 1 층의 n 호와 k 층의 n - 1 호의 합과 같다.
// 왜냐하면 k 층의 n - 1 호는 k - 1 층의 1호부터 n - 1 호까지의 합이기 때문이다.

#include <iostream>

using namespace std;

int getNum(int f, int n);

int main() {
	int floor, roomNumber, input;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> floor >> roomNumber;
		cout << getNum(floor, roomNumber) << '\n';
	}

}

int getNum(int f, int n) {
	if (n == 1)
		return 1;
	if (f == 0)
		return n;
	return (getNum(f - 1, n) + getNum(f, n - 1));
}