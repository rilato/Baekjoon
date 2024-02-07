#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, min, sec;
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        cin >> num;
        sum += num;
    }

    min = sum / 60;
    sec = sum % 60;

    cout << min << '\n' << sec;
}