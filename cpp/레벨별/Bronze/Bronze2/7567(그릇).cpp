#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string S;
    int height = 0;
    char temp;

    cin >> S;

    temp = S[0];

    for (int i = 1; i <= S.size(); i++) {
        if (S[i] != temp)
            height += 10;
        else
            height += 5;

        temp = S[i];
    }

    cout << height;
}