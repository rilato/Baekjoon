// getline 함수의 사용법과
// while문의 조건으로 입력 값을 넣도록 하는 방법을 익힌다

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