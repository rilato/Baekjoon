#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, num;

	cin >> T;

	for (int i = 0; i < T; i++) {
		vector <int> v;
		int sum = 0;

		for (int j = 0; j < 7; j++) {
			cin >> num;

			if (!(num % 2)) {
				sum += num;
				v.push_back(num);
			}
		}

		sort(v.begin(), v.end());

		cout << sum << " " << v.front() << '\n';
	}
}