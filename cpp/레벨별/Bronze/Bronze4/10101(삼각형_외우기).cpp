#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int angle[3];
    int sum = 0;

    for (int i = 0; i < 3; i++) {
        cin >> angle[i];
        sum += angle[i];
    }

    if (sum != 180)
        cout << "Error";

    else if (angle[0] == angle[1] && angle[1] == angle[2])
        cout << "Equilateral";

    else if (angle[0] == angle[1] || angle[1] == angle[2] || angle[0] == angle[2])
        cout << "Isosceles";

    else
        cout << "Scalene";
}