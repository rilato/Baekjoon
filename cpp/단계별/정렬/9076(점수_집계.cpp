#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        vector <int> v;

        for (int j = 0; j < 5; j++) {
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end());

        if (v[3] - v[1] >= 4)
            cout << "KIN" << '\n';

        else {
            int sum = 0;

            for (int i = 1; i < 4; i++)
                sum += v[i];

            cout << sum << '\n';
        }
    }
}