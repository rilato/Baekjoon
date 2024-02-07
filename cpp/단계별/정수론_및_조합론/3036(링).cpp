#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num, gcd, denominator, numerator;
	vector <int> v;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i <= v.size() - 1; i++) {
		// �迭�� ù ��° ���Ҹ� ��������, �ִ� ������� ���Ѵ�.
		gcd = GCD(v[0], v[i]);

		// �и�
		denominator = v[i] / gcd;
		// ����
		numerator = v[0] / gcd;

		cout << numerator << '/' << denominator << '\n';
	}
}

int GCD(int a, int b) {
	int r;

	while (b) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}