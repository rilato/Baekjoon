#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int sum1 = 0;
    int sum2 = 0;
    vector <int> University1;
    vector <int> University2;

    for (int i = 0; i < 10; i++) {
        cin >> num;
        University1.push_back(num);
    }

    for (int i = 0; i < 10; i++) {
        cin >> num;
        University2.push_back(num);
    }

    sort(University1.begin(), University1.end(), greater <int>());
    sort(University2.begin(), University2.end(), greater <int>());

    for (int i = 0; i < 3; i++) {
        sum1 += University1[i];
        sum2 += University2[i];
    }

    cout << sum1 << ' ' << sum2;
}