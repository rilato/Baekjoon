#include <iostream>

using namespace std;

long long N;
long long answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i < N; i++) {
        answer += (N * i + i);
    }

    cout << answer;

    return 0;
}
