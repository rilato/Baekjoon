#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	int sing = 1;
	int cnt = 0;

	cin >> N;

	while (N) {
		if (N < sing)
			sing = 1;

		N -= sing;

		sing++;
		cnt++;
	}

	cout << cnt;
}