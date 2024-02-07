#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N * 2; i++) {
        for (int j = 0; j < N; j++) {
            if (i % 2 && j % 2)
                cout << "*";
            else if (!(i % 2) && !(j % 2))
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }
}