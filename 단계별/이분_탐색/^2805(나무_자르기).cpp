// �ð� �ʰ��� �� Ǯ��
// �̺� Ž���� �������� �ϴ� upper_bound�� ���������,
// for���� ���� ū ������ 1���� �ٿ������Ƿ�, worst case���� �ð��� ���� �ҿ�� �� �ִ�.

// ���� �߿��� sum�� �ڷ����� int�� �ƴ� long long�̴�!!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// inputN�� ������ ��
	// inputM�� ���������� �ϴ� ������ ����
	int inputN, inputM, num;
	vector <int> v;

	cin >> inputN >> inputM;

	for (int i = 0; i < inputN; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	// �迭�� ��� �� ���� ū ������ �ϳ��� �ٿ����鼭 ������ �߶��� �� ������ ���� ���Ѵ�.
	int max = v.back();

	while (1) {
		int sum = 0;
		// index�� max�� ���� ū ���� ���� �迭 ����� index�� ��Ÿ����.
		int index = upper_bound(v.begin(), v.end(), max) - v.begin();

		for (int i = index; i < inputN; i++)
			sum += v[i] - max;

		if (inputM <= sum)
			break;

		--max;
	}

	cout << max;
}



// �迭�� ����� ����
// ans�� �̿����� �ʰ� right�� �̿��� ���� ���

// ���� ū �� ���� ���� int�� ������ ��� �� �����Ƿ�, �ڷ����� long long���� �����Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// inputN�� ������ ��
	// inputM�� ���������� �ϴ� ������ ����
	long long inputN, inputM, num;
	long long max = 0;

	cin >> inputN >> inputM;

	for (int i = 0; i < inputN; i++) {
		cin >> num;
		arr[i] = num;

		// vector�� �ִ� �� �� ���� ū ���� max�� �����Ѵ�.
		if (num > max)
			max = num;
	}

	long long left = 0;
	long long right = max;
	long long mid = 0;

	// ������ ���� ���� �����Ƿ� �ҿ�ð��� ���δ�.

	while (left <= right) {
		long long sum = 0;

		mid = (left + right) / 2;

		for (int i = 0; i < inputN; i++) {
			if (mid < arr[i])
				sum += arr[i] - mid;
		}

		if (sum >= inputM) {
			left = mid + 1;
		}

		else {
			right = mid - 1;
		}
	}

	// while���� ������ ����(left > right)���� Ž���� �ϹǷ�, �������� �� right���� �� ������ �ȴ�.
	cout << right;
}


// vector�� ����� ����
// answer�� ���� �����ϰ� �̸� ���

// ���� ū �� ���� ���� int�� ������ ��� �� �����Ƿ�, �ڷ����� long long���� �����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// inputN�� ������ ��
	// inputM�� ���������� �ϴ� ������ ����
	int inputN, inputM, num;
	int max = 0;
	vector <int> v;

	cin >> inputN >> inputM;

	for (int i = 0; i < inputN; i++) {
		cin >> num;
		v.push_back(num);

		if (num > max)
			max = num;
	}

	long long left = 1;
	long long right = max;
	long long mid = 0;
	long long answer = 0;

	// ������ ���� ���� �����Ƿ� �ҿ�ð��� ���δ�.

	while (left <= right) {
		long long sum = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < inputN; i++) {
			if (mid < v[i])
				sum += v[i] - mid;
		}

		if (inputM <= sum) {
			// ���� ���� ��쿡, mid + 1�� �ϱ� ���� mid ���� answer�� �����Ѵ�.
			answer = mid;
			left = mid + 1;
		}

		else {
			right = mid - 1;
		}
	}

	cout << answer;
}