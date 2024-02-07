#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, num;

    cin >> T;

    while (T--) {
        cin >> num;

        vector<bool> arr(num + 1, false);

        for (int i = 1; i <= num; i++)
            for (int j = i; j <= num; j += i)
                arr[j] = !arr[j];

        int result = 0;

        for (int i = 1; i <= num; i++)
            result += arr[i];

        cout << result << '\n';
    }
}