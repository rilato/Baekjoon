#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;

    cin >> N >> M >> K;

    cout << min(M, K) + min(N - M, N - K);

    return 0;
}