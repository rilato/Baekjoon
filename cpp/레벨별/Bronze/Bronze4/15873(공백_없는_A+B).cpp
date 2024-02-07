#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    string temp = "";
    int answer = 0;

    cin >> s;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i + 1] != '0') {
            temp += s[i];
            answer += stoi(temp);
            temp = "";
        }
        else
            temp += s[i];
    }


    temp += s[s.size() - 1];
    answer += stoi(temp);

    cout << answer;

    return 0;
}