#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int ans = 0;

    cin >> n;

    vector <int> A(n);
    vector <int> B(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), less<>());

    for (int i = 0; i < n; i++) {
        ans += A[i] * B[i];
    }

    cout << ans;
}