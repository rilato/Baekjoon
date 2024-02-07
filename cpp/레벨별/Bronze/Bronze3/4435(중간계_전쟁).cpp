#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, num;
    int gandalf[6] = { 1,2,3,3,4,10 };
    int sauron[7] = { 1,2,2,2,3,5,10 };

    cin >> T;

    for (int i = 1; i <= T; i++) {
        int gandalfSum = 0;
        int sauronSum = 0;

        for (int j = 0; j < 6; j++) {
            cin >> num;
            gandalfSum += num * gandalf[j];
        }

        for (int j = 0; j < 7; j++) {
            cin >> num;
            sauronSum += num * sauron[j];
        }

        cout << "Battle " << i << ": ";

        if (gandalfSum > sauronSum)
            cout << "Good triumphs over Evil\n";
        else if (sauronSum > gandalfSum)
            cout << "Evil eradicates all trace of Good\n";
        else
            cout << "No victor on this battle field\n";
    }
}