#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string a, b;
vector <pair <string, string>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;

        v.push_back({ a, b });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < M; i++) {
        cin >> a;

        int left = 0;
        int right = v.size() - 1;
        int mid = 0;

        while (left <= right) {
            mid = (left + right) / 2;

            if (v[mid].first == a) {
                cout << v[mid].second << '\n';
                break;
            }
            else if (v[mid].first < a)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return 0;
}