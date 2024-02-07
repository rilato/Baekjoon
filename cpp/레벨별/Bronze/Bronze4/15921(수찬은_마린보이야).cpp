#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    if (n != 0)
        cout << "1.00";
    else
        cout << "divide by zero";

    return 0;
}