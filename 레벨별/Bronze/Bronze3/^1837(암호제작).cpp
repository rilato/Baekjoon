// 틀린 풀이
// 에라토스테네스의 체를 이용하여 소수를 잘 구했으나,
// 테스트케이스에서 사용하는 수의 범위가 워낙 크므로,
// 이를 해결했어야 했다.

#include <iostream>

using namespace std;

void check(int product, int K);
bool isPrime(int N);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int product, K;

    cin >> product >> K;

    check(product, K);
}

void check(int product, int K) {
    int printNum = 0;

    for (int i = 1; i * i <= product; i++) {
        if (isPrime(i) && product % i == 0 && isPrime(product / i)) {
            printNum = i;

            if (i >= K && product / i >= K) {
                cout << "GOOD";
                return;
            }
        }
    }

    cout << "BAD " << printNum;
}

bool isPrime(int N) {
    for (int i = 2; i * i <= N; i++)
        if (!(N % i))
            return false;

    return true;
}

// 맞은 풀이
// https://chanqun.tistory.com/204
// https://codecollector.tistory.com/1081

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAX = 1000003;

int K, num;
char P[110];
int arr[MAX - 1];

void primeNum() {
    int sqrt_N = sqrt(MAX) - 1;
    for (int i = 2; i < sqrt_N; i++) {
        if (arr[i] == 0) continue;
        for (int j = i + i; j < MAX; j += i) {
            arr[j] = 0;
        }
    }
}

bool solve(int k) {
    int temp = 0;
    for (int i = 0; P[i]; i++) {
        temp = (temp * 10 + (P[i] - '0')) % k;
    }
    return temp == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> P >> K;

    for (int i = 2; i < MAX; i++) arr[i] = i;

    primeNum();

    bool flag = false;

    for (int i = 2; i < K; i++) {
        if (arr[i] == 0) continue;
        if (solve(i)) {
            flag = true;
            num = i;
            break;
        }
    }

    if (!flag) cout << "GOOD";
    else cout << "BAD " << num;
}