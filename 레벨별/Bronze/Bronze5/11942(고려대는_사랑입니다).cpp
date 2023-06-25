#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string s;

    while (getline(cin, s)) {
        cout << s << '\n';
    }
}