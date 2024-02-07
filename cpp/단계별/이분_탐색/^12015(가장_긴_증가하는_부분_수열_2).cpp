// LIS�� ������ �˾ƾ� �Ѵ�.
// ���Ͱ� ����ְų�, ������ ������ ������ input���� ū ���, ���Ϳ� ���� �ִ´�.
// �׷��� ���� ��� lower_bound�� input�� �� ��ġ�� Ȯ���ϰ�, �� �ڸ��� ���� input���� ��ü�Ѵ�.

// https://ferrante.tistory.com/54
// https://canoe726.tistory.com/9

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a;
vector<int> v;

int main() {
	cin >> a;
	for (int i = 0; i < a; i++) {
		int input;

		cin >> input;

		if (v.empty() || v.back() < input) {
			v.push_back(input);
		}

		// lower_bound�� �̺� Ž���� Ȱ���ϹǷ� ���ĵ� �迭�� �ʿ��ϴ�.
		// ������ v�� �����ϴ� �����̹Ƿ�, ������ �ʿ䰡 ����.

		else {
			// lower_bound�� ��ġ�� �ش��ϴ� �� (*�� ���� �ּҰ� �ƴ�, ���� ��Ÿ��)�� input���� ��ü�Ѵ�.
			*lower_bound(v.begin(), v.end(), input) = input;
		}
	}

	cout << v.size();
}