#include <iostream>

using namespace std;

int N, A, B, C;
int answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> A >> B >> C;

	if (A <= N) {
		answer += A;
	}
	if (A > N) {
		answer += N;
	}
	if (B <= N) {
		answer += B;
	}
	if (B > N) {
		answer += N;
	}
	if (C <= N) {
		answer += C;
	}
	if (C > N) {
		answer += N;
	}

	cout << answer;

	return 0;
}
