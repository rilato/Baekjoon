#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {

        for (int j = i; j <= N - 1; j++)
            cout << " ";

        for (int j = 1; j <= i * 2 - 1; j++) {
            if (j % 2)
                cout << "*";
            else
                cout << " ";
        }

        cout << '\n';
    }
}