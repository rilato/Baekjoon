#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

	int N, F;
	int answer = 0;

	cin >> N >> F;

	N /= 100;
	N *= 100;

	while ((N + answer) % F != 0 && answer < 100)
		answer++;

	if (answer < 10)
		cout << "0";
	cout << answer;
}