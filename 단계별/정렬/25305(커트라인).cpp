#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;

    cin >> N >> K;

    vector <int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    cout << v[N - K];
}