#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	int N;

	cin >> S >> N;

	cout << S[N - 1];
}