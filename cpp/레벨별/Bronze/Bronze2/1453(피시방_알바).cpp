#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool check[101] = { 0, };
    int N, num;
    int count = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;

        if (check[num])
            count++;

        check[num] = true;
    }

    cout << count;
}