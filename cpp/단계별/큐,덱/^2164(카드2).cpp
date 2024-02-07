// 값을 단 한개만 push했을 경우, while문에서 런타임에러가 발생하므로, 예외를 미리 처리해준다.

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

	// 원소가 하나만 있을 때, 런타임 에러가 발생할 수 있으므로 예외를 처리해준다.
	if (q.size() == 1) {
		cout << q.front();
		return 0;
	}

	while (1) {
		// 맨 위의 카드를 버린다.
		q.pop();

		// 버린 후의 카드가 한 장 남으면 반복문을 탈출한다.
		if (q.size() == 1)
			break;

		// 맨 위의 카드를 복사하여 맨 뒤로 넣고, 지워지지 않은 맨 위의 카드를 지워준다.
		q.push(q.front());
		q.pop();
	}

	// 마지막 한 장 남은 카드를 출력한다.
	cout << q.back();
}