// 9471 피사노 주기 문제를 먼저 풀어보아야 한다.

// 틀린 풀이
// 메모리 초과가 난다.
// 배열인데, 1000000000000000이라는 큰 수를 인덱스로 가질 수 없기 때문인 것 같다.

#include <iostream>
#include <vector>

using namespace std;

long long N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector <long long> v(N + 1);

    v[0] = 0;
    v[1] = 1;

    for (int i = 2; i <= N; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 1000000;
    }

    cout << v[N] % 1000000;
}



// 맞은 풀이
// 피사노 주기를 이용하여 해결한다.

#include <iostream>

using namespace std;

long long N;
long long arr[1500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= 1500000; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
    }

    cout << arr[N % 1500000];
}