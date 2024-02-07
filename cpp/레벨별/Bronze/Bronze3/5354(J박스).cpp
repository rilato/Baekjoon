#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, N;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (j == 0 || j == N - 1 || k == 0 || k == N - 1) {
                    cout << "#";
                }
                else
                    cout << "J";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}