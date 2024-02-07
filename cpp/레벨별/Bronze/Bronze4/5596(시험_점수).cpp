#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int mingook[4];
    int manse[4];
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < 4; i++) {
        cin >> mingook[i];
        sum1 += mingook[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> manse[i];
        sum2 += manse[i];
    }

    if (sum1 > sum2)
        cout << sum1;
    else
        cout << sum2;
}