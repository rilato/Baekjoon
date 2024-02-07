#include <iostream>
#include <string>

using namespace std;

int N, B;
string ans = "";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> B;

    while (N != 0) {
        int temp = N % B;

        if (0 <= temp && temp <= 9) {
            ans += to_string(temp);
        }
        else {
            ans += temp - 10 + 'A';
        }

        N /= B;
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}
