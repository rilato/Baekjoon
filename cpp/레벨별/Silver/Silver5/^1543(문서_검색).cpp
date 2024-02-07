#include <iostream>
#include <string>

using namespace std;

string input, s;
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, input);
    getline(cin, s);

    for (int i = 0; i < input.size(); i++) {
        bool flag = true;
        for (int j = 0; j < s.size(); j++) {
            if (input[i + j] != s[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cnt++;
            i += s.size() - 1;
        }
    }

    cout << cnt;

    return 0;
}