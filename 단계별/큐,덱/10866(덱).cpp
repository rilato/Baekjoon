#include <iostream>
#include <vector>

using namespace std;

vector <int> dequeue;

void push_front(int x);
void push_back(int x);
int pop_front();
int pop_back();
void size();
void empty();
void front();
void back();

int main()
{
	int input, num, ans;
	string command;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> command;

		if (command == "push_front") {
			cin >> num;
			push_front(num);
		}

		if (command == "push_back") {
			cin >> num;
			push_back(num);
		}

		if (command == "pop_front") {
			ans = pop_front();
			cout << ans << '\n';
		}

		if (command == "pop_back") {
			ans = pop_back();
			cout << ans << '\n';
		}

		if (command == "size") {
			size();
		}

		if (command == "empty") {
			empty();
		}

		if (command == "front") {
			front();
		}

		if (command == "back") {
			back();
		}
	}
}

void push_front(int x) {
	dequeue.insert(dequeue.begin(), x);
}

void push_back(int x) {
	dequeue.push_back(x);
}

int pop_front() {
	if (dequeue.empty())
		return -1;

	else {
		// temp 를 if문 바깥에 먼저 쓰면 안된다.
		// 값이 비어있는 경우, front()가 무엇을 의미하는지 알 수 없기 때문이다.
		int temp = dequeue.front();
		dequeue.erase(dequeue.begin());
		return temp;
	}
}

int pop_back() {
	if (dequeue.empty())
		return -1;

	else {
		int temp = dequeue.back();
		dequeue.pop_back();
		return temp;
	}
}

void size() {
	cout << dequeue.size() << '\n';
}

void empty() {
	if (dequeue.empty())
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}

void front() {
	if (dequeue.empty())
		cout << -1 << '\n';
	else
		cout << dequeue.front() << '\n';
}

void back() {
	if (dequeue.empty())
		cout << -1 << '\n';
	else
		cout << dequeue.back() << '\n';
}