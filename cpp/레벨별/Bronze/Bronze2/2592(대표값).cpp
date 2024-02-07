#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map <int, int> m;
    int num;
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        cin >> num;

        m[num]++;

        sum += num;
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > cnt) {
            cnt = iter->second;
        }
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == cnt) {
            cout << sum / 10 << '\n' << iter->first;
            return 0;
        }
    }

    return 0;
}
