// 어떤 수 N은 1000000 (백만)까지만 주어지지만,
// N보다 크거나 같고, 팰린드롬인 수 까지 찾아주어야 하므로,
// 소수 및 팰린드롬 수를 찾는 알고리즘 상 1000000 (백만)을 훌쩍 뛰어넘는 수까지 탐색해주어야 한다.

// 1. 시간은 약간 더 걸리지만, 메모리를 조금 사용하는 방식

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;

bool isPrime(int num);
bool isMinPalindrome(string num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // N보다 크거나 같고, 소수이며 팰린드롬인 수를 찾기 위해, 백만보다 큰 수까지 탐색한다.
    for (int i = 2; i < 10000001; i++) {
        if (isPrime(i) && i >= N && isMinPalindrome(to_string(i))) {
            cout << i;
            break;
        }
    }

    return 0;
}

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool isMinPalindrome(string num) {
    int left = 0;
    int right = num.size() - 1;

    while (left < right) {
        if (num[left] != num[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}


// 메모리는 훨씬 많이 잡아먹지만, 시간은 조금 덜 걸리는 방식

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
long A[10000001];

bool isMinPalindrome(string num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++) { // 제곱근 까지만 수행
        if (A[i] == 0) {
            continue;
        }

        for (int j = i + i; j < 10000001; j += i) { // 배수 지우기
            A[j] = 0;
        }
    }

    // N보다 크거나 같고, 소수이며 팰린드롬인 수를 찾기 위해, 백만보다 큰 수까지 탐색한다.
    for (int i = N; i < 10000001; i++) {
        if (A[i] != 0 && isMinPalindrome(to_string(i))) {
            cout << i;
            break;
        }
    }

    return 0;
}

bool isMinPalindrome(string num) {
    int left = 0;
    int right = num.size() - 1;

    while (left < right) {
        if (num[left] != num[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}