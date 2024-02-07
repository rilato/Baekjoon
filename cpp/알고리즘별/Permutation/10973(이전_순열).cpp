#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, k;
int maximum = 0;
bool flag = false;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = N - 1; i > 0; i--) {
        // 거꾸로 살피면서 앞의 숫자가 뒤의 숫자보다 크다면, flag를 true로 바꾸고, 뒤에 나오는 숫자 중 가장 크면서, v[i - 1]보다는 작은 두 숫자를 바꾼다.
        // (예를 들어, 5 1 3 2 4라면, 뒤에서부터 탐색했을 때 5 > 1 이므로, 1부터 마지막 값 중, 5 보다 작은 숫자 중 가장 큰 숫자인 4와 바꾼다.
        // 5 1 2 3 4 -> 4 1 2 3 5
        // 이후 1부터 5까지 수를 내림차순으로 정렬한다.
        if (v[i - 1] > v[i]) {
            flag = true;

            // v[i - 1]보다 작은 값들 중, maximum 값을 찾는다.
            for (int j = i; j < N; j++) {
                if (v[j] < v[i - 1] && v[j] > maximum) {
                    k = j;
                    maximum = v[j];
                }
            }

            int temp = v[k];
            v[k] = v[i - 1];
            v[i - 1] = temp;

            // 바꾼 다음 바로 뒤까지 내림차순으로 정렬한다. (5 1 2 3 4 -> 4 1 2 3 5 -> 5와 4가 바뀌었는데, 기존 5 바로 뒤에 있던 1부터 내림차순 정렬)
            sort(v.begin() + i, v.end(), greater <int>());

            break;
        }
    }

    if (flag) {
        for (int i = 0; i < N; i++) {
            cout << v[i] << " ";
        }
    }
    else {
        cout << -1;
    }

    return 0;
}