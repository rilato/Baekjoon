// �ð� �ʰ��� �� Ǯ��
// binarySearch�Լ��� while�� ���ο��� for���� �ѹ� �� �������ν� �ð��� ������� ���ϴ�. 

#include <iostream>
#include <algorithm>

using namespace std;

void binarySearch(int size, int num);

int N[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputN, inputM, num;

	cin >> inputN;

	for (int i = 0; i < inputN; i++)
		cin >> N[i];

	stable_sort(N, N + inputN);

	cin >> inputM;

	for (int i = 0; i < inputM; i++) {
		cin >> num;

		binarySearch(inputN, num);
	}
}

void binarySearch(int size, int num) {
	int leftIndex = 0;
	int rightIndex = size - 1;
	int count = 0;

	while (leftIndex <= rightIndex) {
		int midIndex = (leftIndex + rightIndex) / 2;

		if (num == N[midIndex]) {
			for (int i = leftIndex; i <= rightIndex; i++)
				if (num == N[i])
					++count;
			break;
		}

		if (num < N[midIndex])
			rightIndex = midIndex - 1;

		if (num > N[midIndex])
			leftIndex = midIndex + 1;
	}

	cout << count << ' ';
}


// �������� Ǯ��

// ���� Ž������ ������ �Լ��� upper_bound�� lower_bound�� Ȱ���Ѵ�.

// ���ĵ� �迭���� Ư�� ���� ũ�ų� ���� �ε����� ��ȯ�ϴ� lower_bound�Լ���
// Ư�� �� ���� ū �ε����� ��ȯ�ϴ� upper_bound �Լ��� ���� �̿��Ͽ� ���� ������ ������ ����.

#include <iostream>
#include <algorithm>

using namespace std;

int N[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputN, inputM, num;

	cin >> inputN;

	for (int i = 0; i < inputN; i++) {
		cin >> N[i];
	}

	sort(N, N + inputN);

	cin >> inputM;

	for (int i = 0; i < inputM; i++) {
		cin >> num;

		cout << upper_bound(N, N + inputN, num) - lower_bound(N, N + inputN, num) << ' ';
	}
}