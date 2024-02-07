// https://cryptosalamander.tistory.com/60

#include <iostream>

using namespace std;

int N;
int arr[11] = { 0, };
int op[4] = { 0, };
int maxNum = -1000000000;
int minNum = 1000000000;

void bt(int result, int index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	bt(arr[0], 1);

	cout << maxNum << '\n' << minNum;
}

void bt(int result, int index) {
	// index == N�̶�� ���� �� ������ �ͼ� ���̻� ����� �ǿ����ڰ� ������ �ǹ��Ѵ�.
	if (index == N) {
		if (result >= maxNum)
			maxNum = result;
		if (result <= minNum)
			minNum = result;
		return;
	}

	// for���� ���� ���̸� �� ��� �İ� ����.
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			// ������ �� ���� ��������Ƿ�, 1�� �ٿ��ش�.
			op[i]--;

			// �˸��� ������ ���ܰ� ���ÿ�, ���� ���ڸ� ����Ű���� index�� ������Ų��.
			// ++index�� index++�� �ϸ� ���ϴ� ����� ������ �ʴ´�.
			if (i == 0)
				bt(result + arr[index], index + 1);
			// else if�� �ƴ� if�� ����ϸ� ���ϴ� ����� ������ �ʴ´�.
			// �� ���� else�� ���������� �����̴�.
			// �׳� if�� ����� �Ÿ� �� �ص� if (i == 3)���� ó���Ѵ�.
			if (i == 1)
				bt(result - arr[index], index + 1);
			if (i == 2)
				bt(result * arr[index], index + 1);
			if (i == 3)
				bt(result / arr[index], index + 1);

			// �̹����� �ٸ� �����ڸ� ����� ���̹Ƿ�, �Ʊ� ����ߴ� �����ڸ� �ٽ� �����Ѵ�.
			op[i]++;
		}
	}
}