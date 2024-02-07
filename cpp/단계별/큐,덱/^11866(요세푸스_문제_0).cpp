// 큐 뒤쪽에 숫자를 이어붙이면서, 앞쪽은 다시 지워주는 방식의 원형 큐를 생각할 수 있어야 한다.

// 큐에 값을 전부 넣고 K - 1까지의 값을 맨 뒤로 넣는다.
// 그렇게 되면 큐의 맨 앞이 K번째의 수가 되고, 다시 그 값을 출력 후 pop해주면 된다.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	queue<int> q;
	cin >> N >> K;

	for (int i = 1; N >= i; i++) {
		q.push(i);
	}

	cout << "<";

	while (!q.empty()) {
		// for문 아래의 pop을 통해 q의 원소가 하나씩 제거되므로, 언젠가는 탈출한다.

		// q에서 출력할 값은 맨 앞으로 놓기 위해, K - 1개의 수를 맨 뒤로 옮긴다.
		// 또한 맨 뒤로 옮기면서, 앞의 숫자는 지운다.
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		// for문을 빠져나오면 K번째 수가 맨 앞에 놓이게 된다.
		// 출력 후 큐에서 해당 값을 지워준다.
		cout << q.front();
		q.pop();

		// 큐가 비어있지 않다면 ,를 찍어준다.
		if (!q.empty()) {
			cout << ", ";
		}
	}

	cout << ">" << endl;
}