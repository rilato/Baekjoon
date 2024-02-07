#include <iostream>

using namespace std;

int N, answer;
int arr[1001][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < 10; i++) {
        arr[0][i] = 1;
    }

    for (int i = 1; i < 1001; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                arr[i][j] = (arr[i][j] + arr[i - 1][k]) % 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        answer = (answer + arr[N - 1][i]) % 10007;
    }

    cout << answer;

    return 0;
}