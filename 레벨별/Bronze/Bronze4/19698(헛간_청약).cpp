#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, W, H, L;

    cin >> N >> W >> H >> L;

    cout << min(N, (W / L) * (H / L));

    return 0;
}