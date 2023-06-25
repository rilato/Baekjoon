#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;

    cin >> T;

    while (T--) {
        int arr[10];

        for (int i = 0; i < 10; i++)
            cin >> arr[i];

        sort(arr, arr + 10);

        cout << arr[7] << '\n';
    }
}