#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string S;

    cin >> N;

    while (N--) {
        cin >> S;

        char lastNum = S[S.size() - 1];
        int num = lastNum - '0';

        if (num % 2)
            cout << "odd\n";
        else
            cout << "even\n";
    }
}