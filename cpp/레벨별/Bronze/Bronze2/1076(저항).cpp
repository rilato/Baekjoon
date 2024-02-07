#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string arr[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
    string color1, color2, color3;
    int idx;
    long long ans;
    long long mul = 1;

    cin >> color1 >> color2 >> color3;

    for (int i = 0; i < 10; i++) {
        if (color1 == arr[i]) {
            ans = i * 10;

            for (int j = 0; j < 10; j++) {
                if (color2 == arr[j]) {
                    ans += j;
                }

                if (color3 == arr[j]) {
                    idx = j;
                }
            }

            break;
        }
    }

    for (int i = 0; i < idx; i++)
        mul *= 10;

    cout << ans * mul;
}