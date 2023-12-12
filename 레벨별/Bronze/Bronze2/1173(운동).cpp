#include <iostream>
#include <algorithm>

using namespace std;

int N, m, M, T, R;
int minute, pulse;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N >> m >> M >> T >> R;

	if (M - m < T) {
		cout << -1;

		return 0;
	}

	pulse = m;

	while (1) {
		if (pulse + T <= M) {
			pulse += T;
			N--;
		}

		else {
			pulse -= R;

			if (pulse < m)
				pulse = m;
		}

		minute++;

		if (N == 0) {
			cout << minute;

			return 0;
		}
	}

    return 0;
}
