// Ʋ�� Ǯ��
// max ���� �ʱ�ȭ�� �� 0�� �ƴ� ������ �ؾ� �Ѵ�.
// sum�� ���� ������ ���� �� �ֱ� �����̴�.
// ���� max�� ������ �����Ѵ�.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, num;
	int sum = 0;
	int count = 0;
	int max = 0;
	vector <int> v;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);

		count++;
		sum += num;

		if (count == K) {
			if (sum >= max)
				max = sum;

			count--;
			sum -= v.front();
			v.erase(v.begin());
		}
	}

	cout << max;
}


// ���� Ǯ��

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, num;
	int sum = 0;
	int count = 0;
	int max = -987654321;
	vector <int> v;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);

		count++;
		sum += num;

		if (count == K) {
			if (sum >= max)
				max = sum;

			count--;
			sum -= v.front();
			v.erase(v.begin());
		}
	}

	cout << max;
}