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
        if (num % i == 0) {     // num���� ������ �������°� ������ �ڽ��� ����ϸ� �ǹǷ�, �Ҽ� ã��� �ٸ��� i < num�� �ƴ϶� i <= num
            cout << i << '\n';
            num /= i;
            --i;
        }
    }
}