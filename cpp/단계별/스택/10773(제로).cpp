#include <iostream>

using namespace std;

int stack[100000];
int tos = -1;
int sum = 0;

void push(int);
void pop();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num;
	string command;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num;

		if (num)
			push(num);
		else
			pop();
	}

	cout << sum;
}

void push(int x) {
	stack[++tos] = x;
	sum += x;
}

void pop() {
	sum -= stack[tos];
	stack[tos--] = 0;
}