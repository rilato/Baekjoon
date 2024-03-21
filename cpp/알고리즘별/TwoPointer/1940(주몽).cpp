#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int cnt = 0;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = v.size() - 1;

    while (left < right) {
        if (v[left] + v[right] == M) {
            ++cnt;
            left++;
        }
        else if (v[left] + v[right] < M) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << cnt;

    return 0;
}
