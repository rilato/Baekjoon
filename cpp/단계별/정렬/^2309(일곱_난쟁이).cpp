// 틀린 풀이
// 옳은 케이스가 한 가지가 아닌, 모두 출력되므로, 문제가 발생한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v;

    int num;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - v[i] - v[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j)
                        cout << v[k] << '\n';
                }
            }
        }
    }
}



// 맞은 풀이
// 정답이 여러 개인 경우, 하나만 출력해서 종료하므로, return 0으로 끝맺을 지점을 정확하게 지정해줘야 한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v;

    int num;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - v[i] - v[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j)
                        cout << v[k] << '\n';
                }

                // 정답이 여러 개인 경우 하나만 출력해야 하므로 프로그램을 종료한다.
                return 0;
            }
        }
    }
}