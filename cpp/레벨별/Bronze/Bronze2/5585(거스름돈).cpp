#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int cnt = 0;
    int money;

    cin >> money;

    money = 1000 - money;

    cnt += money / 500;
    money %= 500;
    cnt += money / 100;
    money %= 100;
    cnt += money / 50;
    money %= 50;
    cnt += money / 10;
    money %= 10;
    cnt += money / 5;
    money %= 5;
    cnt += money / 1;

    cout << cnt;
}