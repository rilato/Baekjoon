#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, midPoint, index;	// x / 2, 짝수일 경우, 중앙에서 하나 오른쪽 값이다.
	int count = 0;

	cin >> N >> M;

	vector <int> dequeue(N);	// 크기가 N인 vector를 할당한다. 1 ~ N까지의 수가 들어간다.
	vector <int> num(M);

	for (int i = 0; i < N; i++)
		dequeue[i] = i + 1;

	for (int i = 0; i < M; i++)
		cin >> num[i];

	for (int i = 0; i < M; i++) {
		// 찾아야 할 수를 number에 저장한다. number는 인덱스다.
		int number = num[i];

		midPoint = dequeue.size() / 2;	// vector의 사이즈로 midPoint를 설정한다. midPoint는 인덱스 값이다.

		for (int j = 0; j < dequeue.size(); j++) {
			if (number == dequeue[j]) {
				index = j;
				break;
			}
		}

		// number의 index가 midPoint보다 작거나 같은 경우 -> 맨 앞의 숫자를 맨 뒤로 보내야 한다.
		if (index <= midPoint) {
			while (1) {
				if (number == dequeue[0])
					break;

				dequeue.push_back(dequeue.front());
				dequeue.erase(dequeue.begin());
				++count;
			}
		}

		// number의 index가 midPoint보다 큰 경우 -> 맨 뒤의 숫자를 맨 앞으로 보내야 한다.
		else {
			while (1) {
				if (number == dequeue[0])
					break;

				dequeue.insert(dequeue.begin(), dequeue.back());
				dequeue.pop_back();
				++count;
			}
		}

		// 원하는 값을 찾았으면 맨 앞의 숫자를 pop한다.
		dequeue.erase(dequeue.begin());
	}

	cout << count;
}