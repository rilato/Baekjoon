// i * i <= N�� ���� ����� ���ϰ� �Ǹ�, �ð� �ʰ��� �߻��Ѵ�.
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
        // ���ڰ� �����ϴ� Ƚ�� N / i�� * �ش� ���� i
        sum += (N / i) * i;
    }

    cout << sum;

    return 0;
}