#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;

    cin >> N >> M >> K;

    //K�� ���� ���� K�� ���� ��� �� ���� ���� ����
    cout << min(min(N / 2, M), (N + M - K) / 3) << "\n";
}