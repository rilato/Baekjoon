#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	int cnt = 0;

	cin >> N;

	vector <int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	cin >> num;

	for (int i = 0; i < N; i++)
		if (num == v[i])
			cnt++;

	cout << cnt;
}