// pair를 두 번 사용하는 방법을 알아둔다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector <pair <pair <int, int>, pair <int, string>>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].second.second >> v[i].second.first >> v[i].first.second >> v[i].first.first;
    }

    sort(v.begin(), v.end());

    cout << v[N - 1].second.second << '\n' << v[0].second.second;
}