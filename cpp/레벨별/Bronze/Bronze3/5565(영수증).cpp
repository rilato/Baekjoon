#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int total;
	int num;

	cin >> total;

	for (int i = 0; i < 9; i++) {
		cin >> num;

		total -= num;
	}

	cout << total;
}