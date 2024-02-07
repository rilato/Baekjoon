// �׻� ���� ū ���� ã�ƾ��Ѵ�?
// �� �� ���� ���� ���ö���� �ڷᱸ���� �켱���� ť��.
// �̸� �̿��ϸ� ���� ���� ���� ���� �߿䵵�� �ٷ� ���� �� �ִ�.

// queue<pair>�� ������ �˾ƾ� �Ѵ�.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int testCase, N, M, num;
	int count = 0;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		// ť�� �켱���� ť�� ������ �׽�Ʈ�ϱ� �� �׻� ������־�� �ϹǷ�, for�� �ۿ� �������� �ʰ�, �ȿ��� �����ؾ� �Ѵ�.
		queue <pair<int, int>> q;
		priority_queue <int> pq;

		cin >> N >> M;

		for (int j = 0; j < N; j++) {
			cin >> num;
			// ť�� �ε����� ���� push
			q.push(make_pair(j, num));

			// ū ������� ������ �켱���� ť�� ���� push
			pq.push(num);
		}

		while (1) {
			// �򰥸����� �� ���� �̸� ��ü�� ������ ����Ѵ�.
			int index = q.front().first;
			int value = q.front().second;
			int max = pq.top();

			// �켱���� ť�� ���� ���� ���� max�� ť�� value���� ���ٸ�, �켱���� ť�� top ���� �����, �ش� ���� ���� ť�� �����ָ�, count�� �ϳ� �ø���.
			if (value == max) {
				pq.pop();
				q.pop();
				++count;
			}

			// ���ϴ� �ε����� �°�, �� ���ڰ� Max ���� ������ count ���� ����Ѵ�.
			if (index == M && value == max) {
				cout << count << '\n';
				break;
			}

			// �켱���� ť�� ���� ���� ���� max�� ť�� value���� �ٸ��ٸ�, ť�� �� ���� ���� ť�� ���� Ǫ���ϰ�, �� ���� ���� �����ش�.
			if (value != max) {
				q.push(q.front());
				q.pop();
			}
		}

		// count�� �ٽ� 0���� �������� �Ѵ�!!
		count = 0;
	}
}