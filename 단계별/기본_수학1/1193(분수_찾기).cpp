#include <iostream>

using namespace std;

int main()
{
	// 1 2 3 4 5	/ 분모
	// 
	// 1 2 4 7 11	/ 총 합, input 값
	//  1 2 3 4		/ d

	int input, numerator;
	int sum = 0;
	int d = 1;

	cin >> input;

	while (1) {
		if (sum < input && input <= sum + d)
			break;
		sum += d;
		++d;
	}

	numerator = input - sum;

	if (d % 2 == 0)
		cout << numerator << "/" << d + 1 - numerator;
	else
		cout << d + 1 - numerator << "/" << numerator;
}


// 다른 풀이

//i번째 대각선에는 i개의 원소가 있으므로,
//N이 몇번째 대각선에 있는지 파악하기 위해
//i를 순차적으로 증가시키며 빼줍니다.
//N이 i보다 작아진 경우 해당 i번째 대각선에 N번째 원소가 존재합니다.

#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int i = 1;

	while (N > i) {
		N -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - N << '/' << N << endl;
	else
		cout << N << '/' << i + 1 - N << endl;
}