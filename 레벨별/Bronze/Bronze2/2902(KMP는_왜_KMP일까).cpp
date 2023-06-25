#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    string ans = "";

    cin >> S;

    ans += S[0];

    for (int i = 1; i < S.size(); i++)
        if (S[i - 1] == '-')
            ans += S[i];

    cout << ans;
}