// 항상 제일 큰 값을 찾아야한다?
// 할 때 가장 먼저 떠올라야할 자료구조는 우선순위 큐다.
// 이를 이용하면 아주 쉽게 가장 높은 중요도를 바로 구할 수 있다.

// queue<pair>의 사용법을 알아야 한다.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int testCase, N, M, num;
	int count = 0;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		// 큐와 우선순위 큐는 값들을 테스트하기 전 항상 비워져있어야 하므로, for문 밖에 선언하지 않고, 안에서 선언해야 한다.
		queue <pair<int, int>> q;
		priority_queue <int> pq;

		cin >> N >> M;

		for (int j = 0; j < N; j++) {
			cin >> num;
			// 큐에 인덱스와 값을 push
			q.push(make_pair(j, num));

			// 큰 순서대로 정렬할 우선순위 큐에 값을 push
			pq.push(num);
		}

		while (1) {
			// 헷갈릴만한 긴 용어는 이를 대체할 변수를 사용한다.
			int index = q.front().first;
			int value = q.front().second;
			int max = pq.top();

			// 우선순위 큐의 가장 위의 값인 max가 큐의 value값과 같다면, 우선순위 큐의 top 값을 지우고, 해당 값을 갖는 큐도 지워주며, count를 하나 늘린다.
			if (value == max) {
				pq.pop();
				q.pop();
				++count;
			}

			// 원하는 인덱스가 맞고, 그 숫자가 Max 값과 같으면 count 값을 출력한다.
			if (index == M && value == max) {
				cout << count << '\n';
				break;
			}

			// 우선순위 큐의 가장 위의 값인 max가 큐의 value값과 다르다면, 큐의 맨 앞의 값을 큐에 새로 푸쉬하고, 맨 앞의 값을 지워준다.
			if (value != max) {
				q.push(q.front());
				q.pop();
			}
		}

		// count를 다시 0으로 만들어줘야 한다!!
		count = 0;
	}
}