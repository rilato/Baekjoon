#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int small = 10001;
    int M, N;
    int sum = 0;
    int cnt = 0;

    cin >> M >> N;

    for (int i = 1; i <= 100; i++) {
        if (i * i >= M && i * i <= N) {
            if (small > i * i)
                small = i * i;

            sum += i * i;
            cnt++;
        }
    }

    if (cnt == 0)
        cout << "-1";
    else
        cout << sum << '\n' << small;
}