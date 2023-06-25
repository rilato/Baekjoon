#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool flag[2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    vector <int> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;

        num += 1000;

        if (flag[num]) {
            continue;
        }
        else {
            flag[num] = true;
            v.push_back(num - 1000);
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}