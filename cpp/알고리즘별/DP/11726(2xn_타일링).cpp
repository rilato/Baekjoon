#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N + 1);

    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i <= N; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 10007;
    }

    cout << v[N] % 10007;

    return 0;
}