// 틀린 풀이
// R을 int로 두면 안된다.
// 또한 ans += 을 사용하면 안된다.
// 그 이유는 맞은 풀이에 자세히 설명

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, num, temp;
    int R = 1;
    int M = 1234567891;
    long long ans = 0;
    string S;

    cin >> N >> S;

    // (A * B) % C = ((A % C) * (B % C)) % C
    for (int i = 0; i < N; i++) {
        // a는 1, b는 2 ... z는 26
        num = S[i] - 'a' + 1;

        ans += (num * R) % M;

        R = R * 31 % M;
    }

    cout << ans;
}


// 맞은 풀이
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, num, temp;
    // R의 범위를 long long으로 지정해줘야 한다.
    long long R = 1;
    int M = 1234567891;
    long long ans = 0;
    string S;

    cin >> N >> S;

    // (A * B) % C = ((A % C) * (B % C)) % C
    for (int i = 0; i < N; i++) {
        // a는 1, b는 2 ... z는 26
        num = S[i] - 'a' + 1;

        // ans +=을 사용하면 ans = ans + ()가 되어 범위를 넘어갈 수 있다.
        // (ans + num * R) 을 M으로 나눠줘야 비로소 안정적인 범위 안에 들어갈 수 있다.
        ans = (ans + num * R) % M;

        // R의 범위를 long long으로 지정해줘야 한다.
        // R * 31이 int의 범위를 넘어설 수 있기 때문.
        R = R * 31 % M;
    }

    cout << ans;
}