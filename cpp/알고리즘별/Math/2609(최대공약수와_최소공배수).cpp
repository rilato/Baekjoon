#include <iostream>

using namespace std;

int A, B;
int gcd, lcm;

int GCD(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    gcd = GCD(A, B);

    lcm = A * B / gcd;

    cout << gcd << '\n' << lcm;

    return 0;
}

int GCD(int a, int b) {
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}