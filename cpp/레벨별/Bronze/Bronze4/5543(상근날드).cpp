#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int set[5];
    int cheapestBurger = 2000;
    int cheapestDrink = 2000;

    for (int i = 0; i < 5; i++) {
        cin >> set[i];

        if (i < 3 && set[i] < cheapestBurger)
            cheapestBurger = set[i];

        if (i >= 3 && set[i] < cheapestDrink)
            cheapestDrink = set[i];
    }

    cout << cheapestBurger + cheapestDrink - 50;
}