// ���� Ž������ ������ ���ڿ��� ã�´�.
// ���� Ž���� ���� ������ ����Ǿ�� �Ѵ�.

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