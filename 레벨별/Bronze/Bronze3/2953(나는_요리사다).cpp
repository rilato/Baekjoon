#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[5][4] = { 0, };
    int person = 0;
    int max = 0;

    for (int i = 0; i < 5; i++) {
        int sum = 0;

        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }

        if (sum >= max) {
            person = i;
            max = sum;
        }
    }

    cout << person + 1 << " " << max;
}