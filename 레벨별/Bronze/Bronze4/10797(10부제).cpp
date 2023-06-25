#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, num;
	int count = 0;

	cin >> N;

	for (int i = 0; i < 5; i++) {
		cin >> num;

		if (N == num)
			count++;
	}

	cout << count;
}