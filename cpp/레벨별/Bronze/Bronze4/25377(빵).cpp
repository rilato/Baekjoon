#include <iostream>
#include <climits>

using namespace std;

int T, a, b;
int answer = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> a >> b;

        if (a <= b) {
            answer = min(answer, b);
        }
    }

    if (answer == INT_MAX) {
        cout << -1;
    }
    else {
        cout << answer;
    }

    return 0;
}
