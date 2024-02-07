// 출력 시 사전순으로 출력해야 하므로, 정렬해야 한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int count = 0;
	string S;
	vector <string> v, newv;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S;

		v.push_back(S);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cin >> S;

		if (binary_search(v.begin(), v.end(), S)) {
			count++;
			newv.push_back(S);
		}
	}

	cout << count << '\n';

	sort(newv.begin(), newv.end());

	for (int i = 0; i < newv.size(); i++) {
		cout << newv[i] << '\n';
	}
}