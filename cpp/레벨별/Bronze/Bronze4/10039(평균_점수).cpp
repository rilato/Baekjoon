#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        cin >> num;

        if (num >= 40)
            sum += num;
        else
            sum += 40;
    }

    cout << sum / 5;
}