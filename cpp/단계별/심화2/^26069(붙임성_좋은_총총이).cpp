#include <iostream>
#include <map>

using namespace std;

int N;
int cnt = 0;
string s1, s2;
map <string, bool> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s1 >> s2;

        if (s1 == "ChongChong")
            m["ChongChong"] = true;

        if (s2 == "ChongChong")
            m["ChongChong"] = true;

        if (m[s1])
            m[s2] = true;

        if (m[s2])
            m[s1] = true;
    }

    // map의 key가 string이므로, for (int i = 0)과 같은 형식 사용 불가. 인덱싱이 안되기 때문.
    for (auto &pair : m) {
        if (pair.second) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
