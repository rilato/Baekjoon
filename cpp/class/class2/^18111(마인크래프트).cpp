// Ʋ�� Ǯ��
// R�� int�� �θ� �ȵȴ�.
// ���� ans += �� ����ϸ� �ȵȴ�.
// �� ������ ���� Ǯ�̿� �ڼ��� ����

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
        // a�� 1, b�� 2 ... z�� 26
        num = S[i] - 'a' + 1;

        ans += (num * R) % M;

        R = R * 31 % M;
    }

    cout << ans;
}


// ���� Ǯ��
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, num, temp;
    // R�� ������ long long���� ��������� �Ѵ�.
    long long R = 1;
    int M = 1234567891;
    long long ans = 0;
    string S;

    cin >> N >> S;

    // (A * B) % C = ((A % C) * (B % C)) % C
    for (int i = 0; i < N; i++) {
        // a�� 1, b�� 2 ... z�� 26
        num = S[i] - 'a' + 1;

        // ans +=�� ����ϸ� ans = ans + ()�� �Ǿ� ������ �Ѿ �� �ִ�.
        // (ans + num * R) �� M���� ������� ��μ� �������� ���� �ȿ� �� �� �ִ�.
        ans = (ans + num * R) % M;

        // R�� ������ long long���� ��������� �Ѵ�.
        // R * 31�� int�� ������ �Ѿ �� �ֱ� ����.
        R = R * 31 % M;
    }

    cout << ans;
}