// 이진 탐색으로 빠르게 문자열을 찾는다.
// 이진 탐색을 위해 정렬이 선행되어야 한다.

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
	vector <string> v;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S;

		v.push_back(S);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cin >> S;

		count += binary_search(v.begin(), v.end(), S);
	}

	cout << count;
}