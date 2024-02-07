#include <iostream>

using namespace std;

void push(int);
int pop();
void isEmpty();
void size();
void top();

int stack[10000];
int tos = -1;

int main() {
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
			isEmpty();

		if (command == "top")
			top();
	}
}

void push(int x) {
	stack[++tos] = x;
}

int pop() {
	if (tos == -1)
		return -1;
	return stack[tos--];
}

void isEmpty() {
	if (tos == -1)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}

void size() {
	cout << tos + 1 << '\n';
}

void top() {
	if (tos == -1)
		cout << -1 << '\n';
	else
		cout << stack[tos] << '\n';
}