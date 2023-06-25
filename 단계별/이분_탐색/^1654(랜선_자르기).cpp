// �̺� Ž���� �����ϱ� ���� �߰� ������ ã�� �������� �� ���� ���ϴ� ����, ������ ����� ��찡 �����.
// ���� long long ���� ��������� �Ѵ�.

// �ּ� ���� �������� Ž���� �ϸ� �ȵȴ�.
// �ּ� ���� �ʿ� ���� ��찡 �ֱ� �����̴�.

// 2 10
// 2
// 100
// => 10cm�� 10���� �ʿ��ϴ�.
// �ּҰ��� 2�� ������ �� ����.

// �ð� �ʰ��� �� Ǯ��

#include <iostream>

using namespace std;

int K[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputK, inputN;
	int count = 0;
	int breakCount = 0;
	int min = 1000000;

	cin >> inputK >> inputN;

	for (int i = 0; i < inputK; i++) {
		cin >> K[i];

		if (K[i] < min)
			min = K[i];
	}

	int left = 0;
	int right = min;
	// ���� ���� ������ ���̸� ��������, ������ ���̵��� �� ���� �ڸ� �� �ִ��� Ȯ���Ѵ�.
	int mid = min;
	int max = 0;

	while (1) {
		// Ż�� ����
		if (breakCount < inputN && inputN <= count)
			break;

		count = 0;
		breakCount = 0;
		max = mid;

		for (int i = 0; i < inputK; i++) {
			// ���� ���� ������ ���̸� ��������, ������ ���̵��� �� ���� �ڸ� �� �ִ��� Ȯ���Ѵ�.
			count += (K[i] / mid);

			// test������ ���� mid���� 1��ŭ ū ���� �־, �� ���� �ڸ� �� �ִ��� Ȯ���Ѵ�.
			// ���� count = 11�ε�, breakCount = 10�̶�� Ż���Ѵ�.
			breakCount += (K[i] / (mid + 1));
		}

		// count�� inputN���� ũ�ٴ� ���� ���̺��� �� �� ���̷� �߶� �ȴٴ� ���� �ǹ��Ѵ�.
		// count�� inputN�� ���Ƶ�, �� ��� �ڸ� �� �ִ��� Ȯ���غ��� �ϹǷ� ���ǿ� = �� �߰��Ѵ�.
		if (count >= inputN) {
			left = mid + 1;
		}

		if (count < inputN) {
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}

	cout << max;
}



// ���� Ǯ��

#include <iostream>

using namespace std;

long long K[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputK, inputN;
	// 1cm�� ������ �ڸ��ٸ�, count�� 21���� �ʰ��ϴ� ���� ������ �� �����Ƿ�, �ڷ����� long long�̴�.
	long long count = 0;
	long long max = 0;

	cin >> inputK >> inputN;

	for (int i = 0; i < inputK; i++) {
		cin >> K[i];

		if (K[i] > max)
			max = K[i];
	}

	// �ڸ��� ���̴� 0�̾�� �ȵȴ�.
	// ���� left�� 1�� �����Ѵ�.
	long long left = 1;
	long long right = max;
	// ���� ū ������ ���̸� ��������, �ϴ� mid ���� �����Ѵ�.
	long long mid = max;

	while (left <= right) {
		count = 0;

		for (int i = 0; i < inputK; i++) {
			// �߰� �� ���̸� ��������, ������ ���̵��� �� ���� �ڸ� �� �ִ��� Ȯ���Ѵ�.
			count += (K[i] / mid);
		}

		// count�� inputN���� ũ�ٴ� ���� ���̺��� �� �� ���̷� �߶� �ȴٴ� ���� �ǹ��Ѵ�.
		// count�� inputN�� ���Ƶ�, �� ��� �ڸ� �� �ִ��� Ȯ���غ��� �ϹǷ� ���ǿ� = �� �߰��Ѵ�.
		if (count >= inputN) {
			left = mid + 1;
		}

		if (count < inputN) {
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}

	cout << mid;
}