// Ʋ�� Ǯ��
// �ߺ��� �����ϱ� ���� bool �Լ��� �����, ���� Ž���� ���� ����Ϸ� �Ͽ���.

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

		// Enter�� ���� Enter ���̿� ������ ������ �� �� �ݺ��Ǵ� ���, �ǳ� ��
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


// ���� Ǯ��
// �� ������ set�� �̿��� Ǯ�� �ȴ�.