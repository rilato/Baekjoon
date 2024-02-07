// R, C, N�� 1,000,000 ������ ����������, ���� ������ ���� ����� int�� ������ �Ѿ�Ƿ� long long�� ������ �Ѵ�.

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long R, C, N;
	long long r, c;

	cin >> R >> C >> N;

	r = R / N;
	c = C / N;

	if (R % N) {
		r++;
	}
	if (C % N) {
		c++;
	}

	cout << r * c;

	return 0;
}