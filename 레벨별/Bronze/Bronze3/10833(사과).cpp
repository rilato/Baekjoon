#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num1, num2;
    int sum = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num1 >> num2;

        sum += num2 % num1;
    }

    cout << sum;
}