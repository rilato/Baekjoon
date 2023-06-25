#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, A, B;
    int Acnt = 0;
    int Bcnt = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A >> B;

        if (A > B)
            Acnt++;

        if (B > A)
            Bcnt++;
    }

    cout << Acnt << " " << Bcnt;
}