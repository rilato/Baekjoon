#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string S;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> S;

        if (S.size() == 1) {
            cout << S[0] << S[0];
        }
        else {
            cout << S[0] << S[S.size() - 1];
        }

        cout << '\n';
    }
}