#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;

	cin >> S;

	vector <int> v;

	for (int i = 0; i < S.size(); i++) {
		v.push_back(S[i] - '0');
	}

	for (int i = 0; i < v.size(); i++) {
		int maximum = 0;
		int idx = 0;

		for (int j = i; j < v.size(); j++) {
			maximum = max(maximum, v[j]);

			if (maximum == v[j])
				idx = j;
		}

		int temp = v[i];
		v[i] = v[idx];
		v[idx] = temp;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}

	return 0;
}