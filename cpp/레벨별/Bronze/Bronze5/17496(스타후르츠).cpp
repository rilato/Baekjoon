#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, T, C, P;

    cin >> N >> T >> C >> P;

    N -= 1;
    N /= T;
    N *= C;
    N *= P;

    cout << N;
}