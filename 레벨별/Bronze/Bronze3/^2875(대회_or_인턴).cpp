#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;

    cin >> N >> M >> K;

    //K가 없을 경우와 K가 있을 경우 중 작은 것을 선택
    cout << min(min(N / 2, M), (N + M - K) / 3) << "\n";
}