#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    int A, B;
    char c;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> A >> c >> B;

        cout << A + B << '\n';
    }
}