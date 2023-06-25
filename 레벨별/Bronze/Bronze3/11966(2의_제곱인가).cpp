#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string S;
    int cnt = 0;

    cin >> S;

    for (int i = 0; i < S.size(); i++) {
        cnt++;

        cout << S[i];

        if (cnt == 10) {
            cnt = 0;
            cout << '\n';
        }
    }
}