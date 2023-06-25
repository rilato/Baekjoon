// 큐에서 가장 앞에 있는 front는 pop시 빠져나올 쪽의 수이다.
// 큐에서 가장 뒤에 있는 back은 push시 들어갈 쪽의 수이다.

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, num;
	string S;
	queue <int> q;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> S;

		if (S == "push") {
			cin >> num;

			q.push(num);
		}

		if (S == "pop") {
			if (q.empty())
				cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}

		if (S == "size") {
			cout << q.size() << '\n';
		}

		if (S == "empty") {
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}

		if (S == "front") {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << '\n';
		}

		if (S == "back") {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << '\n';
		}
	}
}