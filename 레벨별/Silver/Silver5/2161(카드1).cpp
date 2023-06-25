#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	vector <int> v(N);

	for (int i = 1; i <= N; i++) {
		v[i - 1] = i;
	}

	for (int i = 0; i < N; i++) {
		cout << v.front() << " ";

		if (i == N - 1)
			break;

		v.erase(v.begin());

		v.push_back(v.front());

		v.erase(v.begin());
	}
}