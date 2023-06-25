#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, midPoint, index;	// x / 2, ¦���� ���, �߾ӿ��� �ϳ� ������ ���̴�.
	int count = 0;

	cin >> N >> M;

	vector <int> dequeue(N);	// ũ�Ⱑ N�� vector�� �Ҵ��Ѵ�. 1 ~ N������ ���� ����.
	vector <int> num(M);

	for (int i = 0; i < N; i++)
		dequeue[i] = i + 1;

	for (int i = 0; i < M; i++)
		cin >> num[i];

	for (int i = 0; i < M; i++) {
		// ã�ƾ� �� ���� number�� �����Ѵ�. number�� �ε�����.
		int number = num[i];

		midPoint = dequeue.size() / 2;	// vector�� ������� midPoint�� �����Ѵ�. midPoint�� �ε��� ���̴�.

		for (int j = 0; j < dequeue.size(); j++) {
			if (number == dequeue[j]) {
				index = j;
				break;
			}
		}

		// number�� index�� midPoint���� �۰ų� ���� ��� -> �� ���� ���ڸ� �� �ڷ� ������ �Ѵ�.
		if (index <= midPoint) {
			while (1) {
				if (number == dequeue[0])
					break;

				dequeue.push_back(dequeue.front());
				dequeue.erase(dequeue.begin());
				++count;
			}
		}

		// number�� index�� midPoint���� ū ��� -> �� ���� ���ڸ� �� ������ ������ �Ѵ�.
		else {
			while (1) {
				if (number == dequeue[0])
					break;

				dequeue.insert(dequeue.begin(), dequeue.back());
				dequeue.pop_back();
				++count;
			}
		}

		// ���ϴ� ���� ã������ �� ���� ���ڸ� pop�Ѵ�.
		dequeue.erase(dequeue.begin());
	}

	cout << count;
}