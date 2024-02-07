// https://torbjorn.tistory.com/247 참고

// 2의 배수와 5의 배수가 만나 10의 배수를 이루고, 10의 배수는 10을 이룬다.

// 5의 배수의 개수를 센다.
// 5의 배수는 2의 배수와 만나 10의 배수를 이루게 된다.
// 2의 배수는 워낙 많으므로, 5의 배수의 개수만 세어서 거기다 하나씩 붙여주면 10의 배수가 되는 것이다.

// 주의 사항 : 5의 배수 중, 25나 125는 각각 5가 2번, 5가 3번 사용될 수 있으므로, 이에 유념하여 풀이한다.


// 틀린 풀이
// 25나 125 등의 수를 고려하지 않았다.

// 2의 배수와 5의 배수가 만나 10의 배수를 이루고, 10의 배수는 10을 이룬다.

#include <iostream>

using namespace std;

void countZero(int num);

int main()
{
    int num;

    cin >> num;

    countZero(num);
}

void countZero(int num) {
    int count = 0;

    while (1) {
        if (!num)
            break;

        // 5의 배수의 개수를 센다.
        // 5의 배수는 2의 배수와 만나 10의 배수를 이루게 된다.
        // 2의 배수는 워낙 많으므로, 5의 배수의 개수만 세어서 거기다 하나씩 붙여주면 10의 배수가 되는 것이다.
        if (!(num % 5))
            ++count;

        num--;
    }

    cout << count;
}


// 맞은 풀이

#include <iostream>

using namespace std;

void countZero(int num);

int main()
{
    int num;

    cin >> num;

    countZero(num);
}

void countZero(int num) {
    int count = 0;

    for (int i = 5; i <= num; i *= 5) {
        count += num / i;
    }

    cout << count;
}