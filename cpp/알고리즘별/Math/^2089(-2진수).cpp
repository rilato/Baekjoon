// 양수를 양수로 나누는 경우와 음수를 음수로 나누는 경우에는 버림과 내림 방식 모두 문제가 없지만,
// 음수를 양수로 나누거나 양수를 음수로 나누는 경우에는 해석의 차이가 발생할 수 있다.
// -2진수를 구하는 경우에는 내림 방식을 취해줘야 정확한 값을 계산 할 수 있다.
// 따라서 n이 홀수인 경우 내림을 할 수 있도록(n - 1) / -2로 계산을 한다.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    string result;

    while (n != 0) {
        if (n % -2 == 0) {
            result += "0";
            n /= -2;
        }
        else {
            result += "1";
            n = (n - 1) / -2;
        }
    }
    
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }

    return 0;
}
