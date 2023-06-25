// https://velog.io/@sj-lee33/%EB%B0%B1%EC%A4%80-14501%EB%B2%88-%ED%87%B4%EC%82%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-c-%ED%92%80%EC%9D%B4

// �����ٸ��� ��ȯ ���� ������ ���δ�.
// ���ʺ��� Ž���Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Ti[16] = { 0, };
int Pi[16] = { 0, };
int res[16] = { 0, };	// �迭 �ε����� ���ʺ��� ����� ����. res[1]�� �������� Max��

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> Ti[i] >> Pi[i];
	}

	int deadline;

	for (int i = N; i > 0; i--) {
		deadline = i + Ti[i];
		if (deadline > N + 1) {
			// ��� �Ұ��� ���� �ִ� ���� �״�� ���� ��
			res[i] = res[i + 1];
		}
		else {
			// ��� ����, �ִ� ���� �Ǻ� �ʿ� (�ش� ��¥�� �������� ����, �׷��� �ʾ��� ��츦 ��)
			res[i] = max(res[i + 1], res[deadline] + Pi[i]);
		}
	}

	cout << res[1];

	return 0;
}