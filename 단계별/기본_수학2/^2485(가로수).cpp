#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, num, startNum, endNum, temp, gcd;
stack <int> gap;

int GCD(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;

        if (i == 0) {
            startNum = num;
        }

        if (i == N - 1) {
            endNum = num;
        }

        if (i >= 1) {
            gap.push(num - temp);
        }

        temp = num;
    }

    while (1) {
        int a = gap.top();
        gap.pop();
        int b = gap.top();
        gap.pop();

        gap.push(GCD(a, b));

        if (gap.size() == 1) {
            gcd = gap.top();
            break;
        }
    }

    cout << ((endNum - startNum) / gcd) - N + 1;

    return 0;
}

int GCD(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}
