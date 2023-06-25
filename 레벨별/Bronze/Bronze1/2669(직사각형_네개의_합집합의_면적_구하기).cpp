// a, b, c, d는 좌표이므로, 길이를 구할 땐 for문에서 <=가 아닌 <를 써주도록 한다.

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool check[100][100] = { 0, };
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        for (int j = a; j < c; j++) {
            for (int k = b; k < d; k++) {
                if (!check[j][k]) {
                    check[j][k] = 1;
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
}