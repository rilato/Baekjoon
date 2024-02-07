// ���� �� �Ѱ��� push���� ���, while������ ��Ÿ�ӿ����� �߻��ϹǷ�, ���ܸ� �̸� ó�����ش�.

#include <iostream>
#include <queue>

using namespace std;

queue <int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, temp;

	cin >> input;

	for (int i = 0; i < input; i++)
		q.push(i + 1);

	// ���Ұ� �ϳ��� ���� ��, ��Ÿ�� ������ �߻��� �� �����Ƿ� ���ܸ� ó�����ش�.
	if (q.size() == 1) {
		cout << q.front();
		return 0;
	}

	while (1) {
		// �� ���� ī�带 ������.
		q.pop();

		// ���� ���� ī�尡 �� �� ������ �ݺ����� Ż���Ѵ�.
		if (q.size() == 1)
			break;

		// �� ���� ī�带 �����Ͽ� �� �ڷ� �ְ�, �������� ���� �� ���� ī�带 �����ش�.
		q.push(q.front());
		q.pop();
	}

	// ������ �� �� ���� ī�带 ����Ѵ�.
	cout << q.back();
}