#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a, b, c;

    while (1) {
        cin >> a >> b >> c;

        if (!a && !b && !c)
            break;
        else if (a + b <= c || b + c <= a || c + a <= b)
            cout << "Invalid\n";
        else if (a == b && b == c)
            cout << "Equilateral\n";
        else if (a == b || b == c || c == a)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
}