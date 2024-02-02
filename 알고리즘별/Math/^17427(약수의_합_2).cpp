// i * i <= N을 통해 약수를 구하게 되면, 시간 초과가 발생한다.
//https://astrid-dm.tistory.com/300

#include <iostream>

using namespace std;

int N;
long long sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        // 숫자가 등장하는 횟수 N / i번 * 해당 숫자 i
        sum += (N / i) * i;
    }

    cout << sum;

    return 0;
}