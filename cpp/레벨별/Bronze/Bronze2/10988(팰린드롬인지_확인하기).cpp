#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    string ans = "";

    cin >> S;

    for (int i = S.size() - 1; i >= 0; i--)
        ans += S[i];

    if (S == ans)
        cout << 1;
    else
        cout << 0;
}