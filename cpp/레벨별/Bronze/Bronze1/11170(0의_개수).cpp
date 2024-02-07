#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M;

    cin >> T;

    while (T--) {
        int cnt = 0;

        cin >> N >> M;

        for (int i = N; i <= M; i++) {
            string S = to_string(i);

            for (int j = 0; j < S.size(); j++) {
                if (S[j] == '0') {
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
