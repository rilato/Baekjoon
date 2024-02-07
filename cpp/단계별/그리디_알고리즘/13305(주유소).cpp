// 스케줄링을 이용한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int sum = 0;

	cin >> N;

	vector <int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = N; i > 0; i--) {
		sum += i * v[N - i];
	}

	cout << sum;
}