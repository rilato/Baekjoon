#include <iostream>

using namespace std;

int N, M, T;
int a, b, x, y;
int arr[300][300];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> T;

    for (int i = 0; i < T; i++) {
        long long sum = 0;

        cin >> a >> b >> x >> y;

        for (int j = a - 1; j <= x - 1; j++) {
            for (int k = b - 1; k <= y - 1; k++) {
                sum += arr[j][k];
            }
        }

        cout << sum << '\n';
    }
}