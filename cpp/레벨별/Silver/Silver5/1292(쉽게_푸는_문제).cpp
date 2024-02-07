#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int A, B;
	vector <int> v;

	cin >> A >> B;

	int count = 0;
	int number = 0;

	// i는 인덱스
	// number는 들어가는 숫자
	// count는 등장횟수

	for (int i = 0; i <= B; i++) {
		v.push_back(number);

		if (count == number) {
			count = 0;
			number++;
		}

		count++;
	}

	int sum = 0;

	for (int i = A; i <= B; i++) {
		sum += v[i];
	}

	cout << sum;
}