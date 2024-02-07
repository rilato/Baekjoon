#include <iostream>
#include <map>

using namespace std;

int T, n, num;
int maxi = 0;
string univ;
map <string, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> univ >> num;

            m[univ] = num;
        }

        // map을 돌며 최대 값 찾기
        for (auto p : m)
            maxi = max(maxi, p.second);

        // key값을 기준으로 오름차순 정렬되므로, 값을 찾으면 바로 종료
        for (auto p : m) {
            if (p.second == maxi) {
                cout << p.first << '\n';

                break;
            }
        }
    }

    return 0;
}
