#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, d, a;
    char trash;

    cin >> k >> trash >> d >> trash >> a;

    if (k + a < d || d == 0)
        cout << "hasu";

    else
        cout << "gosu";
}