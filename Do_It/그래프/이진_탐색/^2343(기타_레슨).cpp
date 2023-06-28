// ��緹���� �ּ� ���� �Է¹��� ���� �� ���� ū ���̴�.
// ��緹���� �ִ� ���� �Է¹��� ��� ������ ���̴�.
// ���� ������ ���� �������� �ʾƵ� �ȴ�. (left = maximum, right = sum�̰�, �� ���� ��(�������� �ڿ���)���� �����ϹǷ�)
// �� ������ ���� ��, ���� �˸��� ���� ã�� ���� �����̴�.

// �Ϲ����� ���� Ž���� �ٸ���, Ư�� ���� A[mid]�� ���ٴ� ������ ����.
// �������� �־��� ã�� ���� ����, ������ ���� ���� �� ���� Ž���� ��� �����ϱ� �����̴�.

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int maximum = 0;
int sum = 0;
vector <int> A;

int findNum(int left, int right);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];

		if (maximum < A[i])
			maximum = A[i];

		sum += A[i];
	}

	// �߾� ���� ũ��� ��� ������ ������ �� ������ ���� �ε��� = �߾Ӱ� - 1
	// �߾� ���� ũ��� ��� ������ ������ �� ������ ���� �ε��� = �߾Ӱ� + 1

	int ans = findNum(maximum, sum);

	cout << ans;

	return 0;
}

int findNum(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;	// �߰� �ε���
		int cnt = 0;	// ���� ����� ��緹���� ����
		int sum = 0;	// ������ ��

		for (int i = 0; i < N; i++) {
			// �������� ������ �տ�, ���� ���� ���� ���� ���� ���� Ž�� ���� ��緹���� ����� �Ѿ�ٸ�,
			if (sum + A[i] > mid) {
				cnt++;		// ��緹�� ������ �� �� �߰�
				sum = 0;	// ������ ���� 0���� �ʱ�ȭ
			}

			sum += A[i];	// ������ �տ� �ٽ� ���� ���� �ֱ�
		}

		// for���� ���� �� ��緹���� ���� (cnt)�� ������ ��.
		// sum�� �ִٸ�, ������ ��緹���� ������ ������ ���� ���̹Ƿ�, cnt�� 1�� �߰�.
		if (sum != 0) {
			cnt++;
		}
		// count�� ��緹���� ������ �־��� M���� ũ�ٸ�, count ������ �ٿ����ϹǷ�, ��緹���� ����� �ø��� ���� left = mid + 1;
		if (cnt > M) {
			left = mid + 1;
		}
		// count�� ��緹���� ������ �־��� M���� �۴ٸ�, count ������ �÷����ϹǷ�, ��緹���� ����� ���̱� ���� right = mid - 1;
		else {
			right = mid - 1;
		}
	}

	return left;
}