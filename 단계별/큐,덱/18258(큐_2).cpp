// forward는 컴퓨터가 못알아먹으므로 foward를 썼다.
// 여기에 옮길 때만 forward로 적었다.

#include<iostream>

using namespace std;

int queue[2000000];
int rear = -1;	// pop을 위함
int forward = -1;	// push를 위함

void push(int x);
int pop();
void size();
void empty();
void front();
void back();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num, popNum;
	string command;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> command;

		if (command == "push") {
			cin >> num;
			push(num);
		}

		if (command == "pop") {
			popNum = pop();
			cout << popNum << '\n';
		}

		if (command == "size")
			size();

		if (command == "empty")
			empty();

		if (command == "front")
			front();

		if (command == "back")
			back();
	}
}

void push(int x) {
	queue[++rear] = x;
}

int pop() {
	if (rear - forward == 0)
		return -1;
	return queue[++forward];
}

void size() {
	cout << rear - forward << '\n';
}

void empty() {
	if (rear - forward == 0)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}

void front() {
	if (rear - forward == 0)
		cout << -1 << '\n';
	else
		cout << queue[forward + 1] << '\n';
}

void back() {
	if (rear - forward == 0)
		cout << -1 << '\n';
	else
		cout << queue[rear] << '\n';
}