#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, C, D, P;
    int X, Y;

    cin >> A >> B >> C >> D >> P;

    X = A * P;

    if (P <= C)
        Y = B;
    else
        Y = B + (P - C) * D;

    cout << (X <= Y ? X : Y);
}