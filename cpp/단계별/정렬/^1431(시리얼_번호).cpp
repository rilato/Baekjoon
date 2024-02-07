// vector�� type���� <����ü>�� ���� �� �ִ�.
// �� ������ int, string ���� ���� �� �ִ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	string input;

	cin >> N;

	// ������ ����� Ȯ���ϰ� ������� ������ ������ ����� ������ �߻����� �ʴ´�.
	vector<string> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i] << '\n';
	}
}

bool compare(string a, string b) {
	// ���̰� �ٸ� ��� ª�� ���� ���� �´�.
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		int asize = a.size();
		int bsize = b.size();
		int asum = 0;
		int bsum = 0;

		// ������ ���, �� ���� ���Ѵ�.
		for (int i = 0; i < asize; i++) {
			if (0 <= a[i] - '0' && a[i] - '0' <= 9)
				asum += a[i] - '0';
		}

		for (int i = 0; i < bsize; i++) {
			if (0 <= b[i] - '0' && b[i] - '0' <= 9)
				bsum += b[i] - '0';
		}

		// ������ ���� �ٸ� ���, ������ ���� ���� ���� ���� ������ �Ѵ�.
		if (asum != bsum)
			return asum < bsum;
		// ������ ���� ���� ���, ���ĺ� ������ ���� �Ѵ�.
		else
			return a < b;
	}
}