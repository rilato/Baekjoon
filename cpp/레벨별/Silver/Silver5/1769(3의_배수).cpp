#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    int cnt = 0;

    cin >> S;

    while (S.size() != 1) {
        int temp = 0;

        for (int i = 0; i < S.size(); i++) {
            temp += S[i] - '0';
        }

        S = to_string(temp);
        cnt++;
    }

    cout << cnt << '\n';

    if (stoi(S) % 3) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}
