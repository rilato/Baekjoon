#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string S;
int B;
int j = 0;
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S >> B;

    for (int i = S.size() - 1; i >= 0; i--) {
        if ('0' <= S[i] && S[i] <= '9') {
            int temp = S[i] - '0';
            ans += pow(B, j) * temp;
        }
        else {
            int temp = S[i] - 'A' + 10;
            ans += pow(B, j)* temp;
        }
        j++;
    }

    cout << ans;

    return 0;
}
