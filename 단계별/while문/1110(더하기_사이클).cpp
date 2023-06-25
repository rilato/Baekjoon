#include <iostream>

using namespace std;

int sum_cycle(int N);

int main()
{
	int N, newNum;
	int ret = 0;
	int count = 0;

	cin >> N;

	newNum = N;	// 입력받은 문자 N을 다른 저장 공간에 복사해두기


	while (1) {
		ret = sum_cycle(newNum);
		++count;
		if (ret == N)
			break;
		newNum = ret;
	}


	cout << count;
}

int sum_cycle(int N)
{
	int sum, one;

	if (N >= 10) {
		sum = N / 10 + N % 10;
		one = N % 10;
		return one * 10 + sum % 10;
	}

	if (N < 10)
		return N * 10 + N;
}



// 다른 코드

#include <iostream>
using namespace std;

int main() {
	int n;
	int cnt = 0;
	int num, temp;
	cin >> n;
	num = n;

	while (1) {
		temp = (n % 10) * 10 + (n / 10 + n % 10) % 10;
		cnt++;
		n = temp;
		if (temp == num)
			break;
	}
	cout << cnt << '\n';
}