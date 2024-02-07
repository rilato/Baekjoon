// C언어의 scanf를 사용하면 쉽게 해결 가능하다.
// 16진수를 나타내는 "%x"를 활용한다.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {
    int num;

    scanf("%x", &num);

    printf("%d", num);

    return 0;
}


// C언어 스타일이 아니더라도 풀이가 가능하다.
// cin >> hex >> 정수; 형식을 활용한다.

#include <iostream>
using namespace std;

int main(void) {
    int a;

    cin >> hex >> a;

    cout << a;
}