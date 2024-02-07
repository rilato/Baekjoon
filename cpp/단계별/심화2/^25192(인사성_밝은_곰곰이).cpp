// 틀린 풀이
// 중복을 제거하기 위한 bool 함수를 만들고, 이진 탐색을 통해 계산하려 하였다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int len = 0;
string S;
vector <string> v;

bool check(string S);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S;

		if (S == "ENTER") {
			len += v.size();
			v.clear();
			continue;
		}

		// Enter와 다음 Enter 사이에 동일한 내용이 두 번 반복되는 경우, 건너 뜀
		if (check(S))
			continue;

		v.push_back(S);
	}

	cout << len + v.size();

	return 0;
}

bool check(string S) {
	int left = 0;
	int right = v.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (v[mid] < S) {
			left = mid + 1;
		}
		else if (v[mid] > S) {
			right = mid - 1;
		}
		else if (v[mid] == S) {
			return true;
		}
	}

	return false;
}


// 맞은 풀이
// 더 간단한 set을 이용해 풀면 된다.