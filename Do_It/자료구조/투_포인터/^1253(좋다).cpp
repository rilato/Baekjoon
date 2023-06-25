// 수의 위치가 다르면 값이 같아도 다른 수이다!!
// ex) 1 1 1 -> 서로 다른 수!
// lp == nowp, rp == nowp인 경우도 배제!
// 음수도 고려해야 한다.
// 따라서 nowp (현재 보고있는 수의 인덱스 값)도 0부터 시작해서 모두 고려해줘야 한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, temp;
    int cnt = 0;
    vector <int> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (int nowp = 0; nowp < N; nowp++) {
        int find = v[nowp];
        int lp = 0;
        int rp = N - 1;

        while (lp < rp) {
            int sum = v[lp] + v[rp];

            if (sum == find) {
                if (lp != nowp && rp != nowp) {
                    cnt++;
                    break;
                }
                // 현재 가리키는 인덱스 != lp가 가리키는 인덱스여야 하므로
                // 같은 경우에는 lp를 하나 더 늘려준다.
                else if (lp == nowp) {
                    lp++;
                }
                else if (rp == nowp) {
                    rp--;
                }
            }

            else if (sum < find) {
                lp++;
            }

            else if (sum > find) {
                rp--;
            }
        }
    }

    cout << cnt;

    return 0;
}