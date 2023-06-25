// 92를 넣었을 때 부터 값이 이상해진다. (음수가 나옴)
// 나머지 연산을 중간에 넣어주면 예를 들어 arr[91]은 나머지 값이고 arr[90]는 원래 값이어서 더해지는 값을 다시 10007로 나누었을 때, 실제의 값과 오차가 있을 줄 알았다.
// 나머지 연산을 중간에 해줘도 어차피 최종 결과가 나머지를 원하는 계산이므로, 계산 결과는 바뀌지 않나보다.

// 틀린 풀이

#include <iostream>

using namespace std;

int n;
long long arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[n] % 10007;
}


// 맞은 풀이

#include <iostream>

using namespace std;

int n;
long long arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        int temp = arr[i - 1] + arr[i - 2];

        if (temp > 10007) {
            temp %= 10007;
        }

        arr[i] = temp;
    }

    cout << arr[n] % 10007;
}