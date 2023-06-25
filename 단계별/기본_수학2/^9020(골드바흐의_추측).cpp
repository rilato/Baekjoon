// 4 �̻��� ¦���� ��� �� �Ҽ��� ������ �̷������. ex) 8 = 3 + 5 / 10 = 5 + 5 or 3 + 7
// �̸� �������� �����̶�� �Ѵ�.

// for���� �ִ��� ���� ����ؾ� �Ѵ�.
// �������� ���� ����, ¦���� ������ �ɰ� ��, ���� ���� ���� �۰�, ���� ���� ���� ũ���Ͽ� �� �Ҽ��� ���� ���� ���� ����� �ȴ�.
// �Ҽ� + �Ҽ� = ¦������ �Ҽ� = ¦�� - �Ҽ��̴�.
// ���� for���� ���� �� num/2���� �����ϸ�, ���� ���� i�� ���, i�� �������� �ϳ��� �ٿ�������.

#include <iostream>
#include <cmath>

using namespace std;

bool isPrimeNumber(int num);

int main() {
	int input, evenNum;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> evenNum;

		for (int i = evenNum / 2; i > 1; i--) {       // ���� ������ �ɰ��� ���� ���� i, ���� ���� j�� ���´�.
			int j = evenNum - i;

			if (isPrimeNumber(i) && isPrimeNumber(j)) {
				cout << i << ' ' << j << '\n';
				break;
			}
		}
	}
}

bool isPrimeNumber(int num) {
	int root = sqrt(num);

	for (int i = 2; i <= root; i++) {
		if (!(num % i))	// �������� 0�̸� �ռ���
			return 0;
	}

	return 1;
}


// �ð� �ʰ��� �� Ǯ�� -> �����Ҵ��� ���� �迭�� �ް�, ������ �ʱ�ȭ���ִ� �۾����� �ð��� ���� �ɸ� ���ϴ�.

#include <iostream>
#include <cmath>

using namespace std;

void goldbach(int num);

int main() {
	int input, evenNum;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> evenNum;
		goldbach(evenNum);
	}
}

void goldbach(int num) {
	int* arr = new int[num];
	int j = 0;

	for (int i = 0; i < num; i++)
		arr[i] = 1;

	for (int i = 2; i <= num - 1; i++) {			// �Ҽ��� ���� 1��, �Ҽ��� ���� 0���� �ʱ�ȭ
		for (int j = 2; j <= (int)sqrt(num); j++) {
			if (!(i % j))
				arr[i] = 0;
		}
	}

	for (int i = num / 2; i > 1; i--) {
		if (arr[i] == 1) {
			j = num - i;
			if (arr[j] == 1) {
				cout << i << ' ' << j << '\n';
				break;
			}
		}
	}

	delete[] arr;
}