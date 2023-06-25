#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	string S;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string newS;

		cin >> S;

		for (int j = 0; j < S.size(); j++) {
			newS += tolower(S[j]);
		}

		cout << newS << '\n';
	}
}