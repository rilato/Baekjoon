#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int arr[26] = { 0, };
    string S;

    cin >> S;

    for (int i = 0; i < S.size(); i++)
        arr[S[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        cout << arr[i] << " ";
}