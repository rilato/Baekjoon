#include <iostream>

using namespace std;

int N, T;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < 5; i++) {
        cin >> T;

        if (N == T)
            ans++;
    }

    cout << ans;

    return 0;
}