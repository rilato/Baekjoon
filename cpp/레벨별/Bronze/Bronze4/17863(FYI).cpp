#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;

    if (s[0] == '5' && s[1] == '5' && s[2] == '5')
        cout << "YES";
    else
        cout << "NO";

    return 0;
}