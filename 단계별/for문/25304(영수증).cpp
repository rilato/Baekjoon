#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int X, N;
    long long a, b;
    long long sum = 0;

    cin >> X >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;

        sum += a * b;
    }

    if (sum == X)
        cout << "Yes";
    else
        cout << "No";
}