#include <iostream>

using namespace std;

void findFactors(int num);

int main() {
    int num;

    cin >> num;

    findFactors(num);
}

void findFactors(int num) {
    if (num == 1)
        return;

    for (int i = 2; i <= num; i++) {
        if (num % i == 0) {     // num까지 돌려서 나눠지는게 없으면 자신을 출력하면 되므로, 소수 찾기와 다르게 i < num이 아니라 i <= num
            cout << i << '\n';
            num /= i;
            --i;
        }
    }
}