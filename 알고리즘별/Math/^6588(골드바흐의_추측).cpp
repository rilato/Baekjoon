// https://minyeok2ee.gitlab.io/boj/boj-6588/

#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000001] = { 0, };
vector <int> prime;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 에라토스테네스의 체
    for (int i = 2; i <= 1000000; i++) {
        arr[i] = i;
    }

    for (int i = 2; i * i <= 1000000; i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = i * i; j <= 1000000; j += i) {
            arr[j] = 0;
        }
    }

    // 골드바흐의 추측에서는, 짝수 = 홀수소수 + 홀수소수이므로, 소수 2는 무관함
    for (int i = 3; i <= 1000000; i++) {
        if (arr[i] != 0) {
            prime.push_back(i);
        }
    }

    while (1) {
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < prime.size(); i++) {
            // arr배열 (인덱스와 소수가 일치)
            // prime배열 (소수들만 모아놓음)
            if (arr[n - prime[i]] == n - prime[i]) {
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                break;
            }
        }
    }

    return 0;
}
