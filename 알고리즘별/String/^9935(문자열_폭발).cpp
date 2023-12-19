#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, bomb;

    cin >> s >> bomb;

    while (1) {
        int idx = s.find(bomb, 0);

        if (idx == -1)
            break;

        s.erase(s.begin() + idx, s.begin() + idx + bomb.size());
    }

    if (s.size() == 0) {
        cout << "FRULA";
    }
    else {
        cout << s;
    }

    return 0;
}
