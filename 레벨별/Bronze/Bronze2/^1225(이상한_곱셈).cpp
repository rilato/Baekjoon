// 시간 초과가 난 풀이
// stoi를 사용하였더니 시간 초과가 발생했다.

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


// 맞은 풀이
// '0'을 빼주어 문자를 숫자로 바꿔주었다.

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