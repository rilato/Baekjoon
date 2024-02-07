// �ð� �ʰ��� �� Ǯ��
// stoi�� ����Ͽ����� �ð� �ʰ��� �߻��ߴ�.

#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string A, B, a, b;
    long long ans = 0;

    cin >> A >> B;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            a = A[i];
            b = B[j];

            ans += stoi(a) * stoi(b);
        }
    }

    cout << ans;
}


// ���� Ǯ��
// '0'�� ���־� ���ڸ� ���ڷ� �ٲ��־���.

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string A, B;
    long long ans = 0;

    cin >> A >> B;

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            ans += (A[i] - '0') * (B[j] - '0');

    cout << ans;
}