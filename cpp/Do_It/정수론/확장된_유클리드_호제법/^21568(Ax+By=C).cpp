#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long gcd(long a, long b);
vector<long> Excute(long a, long b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long a, b, c;

    cin >> a >> b >> c;

    long tgcd = gcd(a, b);

    if (c % tgcd != 0) {
        cout << -1 << "\n";
    }

    else {
        int mok = (int)(c / tgcd);
        vector<long> ret = Excute(a, b);    // 나머지 (b)가 0이 될 때까지 재귀 함수 호출하는 유클리드 호제법 함수 호출

        cout << ret[0] * mok << " " << ret[1] * mok;    // 각 결과값에 (c / 최대공약수) 값을 곱하여 주고 해당 값을 출력하기
    }
}

// 유클리드 호제법 함수 구현
vector<long> Excute(long a, long b) {
    vector<long> ret(2);

    if (b == 0) {
        ret[0] = 1;
        ret[1] = 0;

        return ret;
    }

    long q = a / b;
    vector<long> v = Excute(b, a % b); 	// 재귀 형태로 호제법 수행

    // X = Y' , Y = X' - (Y' * 몫)을 계산하는 역산 로직 구현
    ret[0] = v[1];  		// 역으로 올라오면서 X, Y 값을 계산하는 로직
    ret[1] = v[0] - v[1] * q;

    return ret;
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}