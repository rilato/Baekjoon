// 틀린 풀이
// 이진 탐색을 하지 않아, 시간 초과가 발생했다.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;
	vector <int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		v.push_back(num);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;

		for (int j = 0; j < v.size(); j++) {
			if (v[j] == num) {
				cout << 1 << " ";
				break;
			}
			if (j == v.size() - 1 && v[j] != num)
				cout << 0 << " ";
		}
	}
}



// 맞은 풀이
// 내장된 함수인 binary_search()를 이용하여 이진 탐색을 적용하였다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;
	vector <int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;

		cout << binary_search(v.begin(), v.end(), num) << " ";
	}
}