// 삽입 정렬을 코딩하는 방법을 알아둔다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	vector <int> v(N, 0);
	vector <int> sum(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// insertion sort
	for (int i = 1; i < N; i++) {
		int insert_point = i;
		int insert_value = v[i];

		for (int j = i - 1; j >= 0; j--) {
			if (v[j] < v[i]) {
				insert_point = j + 1;
				break;
			}
			if (j == 0) {
				insert_point = 0;
			}
		}

		for (int j = i; j > insert_point; j--) {
			v[j] = v[j - 1];
		}

		v[insert_point] = insert_value;
	}

	sum[0] = v[0];	// 합 배열 만들기

	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + v[i];
	}

	int total = 0;

	for (int i = 0; i < N; i++) {
		total += sum[i];
	}

	cout << total;

	return 0;
}