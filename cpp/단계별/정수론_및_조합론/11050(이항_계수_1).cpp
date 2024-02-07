#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, breakPoint;
	int numerator = 1;
	int denominator = 1;
	int count = 0;

	cin >> N >> K;

	breakPoint = K;

	while (count != breakPoint) {
		count++;

		numerator *= N--;
		denominator *= K--;
	}

	cout << numerator / denominator;
}


// �ٸ� Ǯ��
// nCk = n! / (k! * (n-k)!) �̿� �� ��� ��

#include<iostream>

using namespace std;

//��� �̿�.
int Factorial(int num) {
	if (num == 1 || num == 0) {
		return 1;

	}
	else {
		return Factorial(num - 1) * num;
	}

}

int main(void) {

	int n, k;

	cin >> n >> k;

	cout << Factorial(n) / (Factorial(k) * Factorial(n - k));

	return 0;
}


��ó: https://blockdmask.tistory.com/93 [������ ������]