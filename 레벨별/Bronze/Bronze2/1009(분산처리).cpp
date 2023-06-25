// 런타임 에러가 난 풀이
// 1000000을 돌리는 for문이 길어지면 시간 초과가 날줄 알고 짠 코드

#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long N, a, b;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int arr[11] = { 0, };
        vector <int> v;
        bool check = false;
        int ans = 1;

        cin >> a >> b;

        a %= 10;

        for (int j = 1; j <= b; j++) {
            if (check)
                break;

            ans *= a;
            ans %= 10;

            if (ans == 0)
                arr[10]++;
            else
                arr[ans]++;

            if (arr[ans] == 1)
                v.push_back(ans);

            if (arr[ans] == 2)
                check = true;
        }

        b %= v.size();

        if (b == 0)
            b = v.size();

        cout << v[b - 1] << '\n';
    }
}


// 맞은 풀이

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, a, b;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int ans = 1;

        cin >> a >> b;

        for (int j = 0; j < b; j++)
            ans = (ans * a) % 10;

        if (ans == 0)
            cout << 10 << '\n';
        else
            cout << ans << '\n';
    }
}