#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    int arr[26] = { 0, };
    bool flag = false;
    string S;
    char c;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S;

        arr[S[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] >= 5) {
            flag = true;
            c = i + 'a';
            cout << c;
        }
    }

    if (!flag)
        cout << "PREDAJA";
}