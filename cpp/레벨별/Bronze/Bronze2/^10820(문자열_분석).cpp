// T의 개수가 주어지지 않았을 때, 어떻게 입력을 받아야 끝낼 수 있는지 파악한다.

#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string s;

    while (getline(cin, s)) {
        int arr[4] = { 0, };

        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                if (isupper(s[i]))
                    arr[1]++;
                else
                    arr[0]++;
            }
            else if (isdigit(s[i]))
                arr[2]++;
            else
                arr[3]++;
        }

        for (int i = 0; i < 4; i++) {
            cout << arr[i] << " ";
        }

        cout << '\n';
    }
}