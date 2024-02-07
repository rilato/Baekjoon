#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, P, M, num;;

    cin >> T;

    while (T--) {
        bool flag[501] = { 0, };
        int cnt = 0;

        cin >> P >> M;

        for (int i = 0; i < P; i++) {
            cin >> num;

            flag[num] = true;
        }

        for (int i = 0; i < 501; i++) {
            if (flag[i])
                cnt++;
        }

        cout << P - cnt << '\n';
    }
}