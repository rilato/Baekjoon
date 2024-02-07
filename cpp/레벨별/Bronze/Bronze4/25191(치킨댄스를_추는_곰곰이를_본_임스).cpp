#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, A, B;
	int chicken;

	cin >> N >> A >> B;

	A /= 2;

	chicken = A + B;

	if (chicken >= N)
		cout << N;
	else
		cout << chicken;
}