#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	cout << floor(sqrt(N));

	return 0;
}