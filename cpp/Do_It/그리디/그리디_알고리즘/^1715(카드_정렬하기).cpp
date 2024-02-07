// �׻� �ּ� �� �� ���� �̱� ����, priority queue�� ����Ѵ�.

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	int answer = 0;

	cin >> N;

	// �켱���� ť�� �⺻������ ���� ū ���� ���� ū �켱������ �����Ƿ�(��������)
	// ������������ �����Ϸ��� greater<int>�� ���־�� �Ѵ�.
	priority_queue <int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}

	// priority_queue�� �̿��ϸ�, ���� �ڵ� ���ĵǹǷ�
	// ���� ���� ī�� ���� 2���� ���� ���� �� �ִ�.
	while (pq.size() != 1) {
		int num1 = pq.top();
		pq.pop();

		int num2 = pq.top();
		pq.pop();

		answer += (num1 + num2);

		pq.push(num1 + num2);
	}

	cout << answer;

	return 0;
}