#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string A, B, ans;
    int temp;

    cin >> A >> B;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    temp = stoi(A) + stoi(B);

    while (1) {
        if (temp % 10 == 0)
            temp /= 10;
        else
            break;
    }

    ans = to_string(temp);

    reverse(ans.begin(), ans.end());

    cout << ans;
}