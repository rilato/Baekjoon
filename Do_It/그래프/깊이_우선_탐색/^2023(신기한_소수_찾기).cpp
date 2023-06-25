// visited �迭�� ������� �ʴ� DFS ����
// pruning�� �̿��� ��Ʈ��ŷ ����� ����

#include <iostream>

using namespace std;

int N;

void DFS(int number, int jarisu);
bool isPrime(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// ù �ڸ��� 2, 3, 5, 7�� �����ؾ� ù ��° �ڸ��� �Ҽ���� ������ ����
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}

void DFS(int number, int jarisu) {
	// ���� (���) ���� ����
	if (jarisu == N) {
		if (isPrime(number)) {
			cout << number << '\n';
		}

		return;
	}

	//for (int i = 0; i < 10; i++) {
	//	// ¦���� ���, ������ �Ҽ��� �ƴϹǷ� �н�
	//	if (i % 2 == 0) {
	//		continue;
	//	}

	//	// ���� Ž������ number�� 10�� ���ϰ� i�� ���� �� (�ڸ��� + 1�� ��)�� �Ҽ����ٸ�, Ž�� ����
	//	if (isPrime(number * 10 + i)) {
	//		DFS(number * 10 + i, jarisu + 1);
	//	}
	//}

	for (int i = 1; i < 10; i += 2) {
		if (isPrime(number * 10 + i)) {
			DFS(number * 10 + i, jarisu + 1);
		}
	}
}

bool isPrime(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}