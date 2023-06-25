#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string S;
    char C;
    string ans = "";

    getline(cin, S);

    for (int i = 0; i < S.size(); i++) {
        if (isalpha(S[i])) {
            if ('a' <= S[i] && S[i] <= 'm' || 'A' <= S[i] && S[i] <= 'M')
                ans += S[i] + 13;
            else if ('n' <= S[i] && S[i] <= 'z' || 'N' <= S[i] && S[i] <= 'Z')
                ans += S[i] - 13;
        }

        else
            ans += S[i];
    }

    cout << ans;
}