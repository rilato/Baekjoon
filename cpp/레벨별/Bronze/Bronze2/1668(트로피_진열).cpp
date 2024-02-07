#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp = 0;
    int count1 = 0;
    int count2 = 0;

    cin >> num;

    vector <int> v(num);

    for (int i = 0; i < num; i++) {
        cin >> v[i];

        if (v[i] > temp) {
            temp = v[i];
            ++count1;
        }
    }

    temp = 0;

    for (int i = num - 1; i >= 0; i--) {
        if (v[i] > temp) {
            temp = v[i];
            ++count2;
        }
    }

    cout << count1 << '\n' << count2;
}