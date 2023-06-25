#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    if (N >= 3 && M <= 4)
        cout << "TroyMartian\n";
    if (N <= 6 && M >= 2)
        cout << "VladSaturnian\n";
    if (N <= 2 && M <= 3)
        cout << "GraemeMercurian\n";

    return 0;
}