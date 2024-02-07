// 틀린 풀이

#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long N, B, C;
    long long cnt = 0;

    cin >> N;

    vector <long long> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        if (v[i] >= B) {
            v[i] -= B;
            cnt++;
        }

        if (v[i] % C) {
            v[i] /= C;
            v[i]++;

            cnt += v[i];
        }

        else if (!(v[i] % C)) {
            v[i] /= C;

            cnt += v[i];
        }
    }

    cout << cnt;
}


// 맞은 풀이

#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long N, B, C;
    long long cnt = 0;

    cin >> N;

    vector <long long> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        v[i] -= B;

        if (v[i] <= 0)
            cnt++;

        else {
            cnt++;

            if (v[i] % C) {
                v[i] /= C;
                v[i]++;

                cnt += v[i];
            }
            else {
                v[i] /= C;

                cnt += v[i];
            }
        }
    }

    cout << cnt;
}