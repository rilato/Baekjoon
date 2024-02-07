#include <iostream>

using namespace std;

int tos = 0;

void push();
int pop();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, ans;
	string ps, sign;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> ps;

		for (int j = 0; j < ps.size(); j++) {
			sign = ps.substr(j, 1);

			if (sign == "(")
				push();

			if (sign == ")") {
				ans = pop();

				if (ans == -1)
					break;
			}

		}

		if (!tos)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		tos = 0;
	}
}

void push() {
	++tos;
}

int pop() {
	--tos;

	if (tos < 0)
		return -1;
	else
		return 0;
}