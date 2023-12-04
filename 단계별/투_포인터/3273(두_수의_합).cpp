#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num, X;
int cnt = 0;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;

        v.push_back(num);
    }

    cin >> X;

    sort(v.begin(), v.end());

    int left = 0;
    int right = N - 1;

    while (left < right) {
        if (v[left] + v[right] == X) {
            cnt++;
            left++;
        }
        else if (v[left] + v[right] > X) {
            right--;
        }
        else {
            left++;
        }
    }

    cout << cnt;

    return 0;
}
