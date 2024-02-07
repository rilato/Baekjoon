#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
int sum = 0;
int num1, num2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    v.resize(9);

    for (int i = 0; i < 9; i++) {
        cin >> v[i];

        sum += v[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            int ans = sum - v[i] - v[j];

            if (ans == 100) {
                num1 = v[i];
                num2 = v[j];
                break;
            }
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 9; i++) {
        if (v[i] == num1 || v[i] == num2) {
            continue;
        }

        cout << v[i] << '\n';
    }

    return 0;
}