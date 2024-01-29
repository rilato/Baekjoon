#include <iostream>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	if (N * 100 >= M) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
