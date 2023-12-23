#include <iostream>
#include <string>

using namespace std;

string s;
string str = "UCPC";
int j = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == str[j]) {
            j++;
        }
    }

    if (j < 4) {
        cout << "I hate UCPC";
    }
    else {
        cout << "I love UCPC";
    }

    return 0;
}
