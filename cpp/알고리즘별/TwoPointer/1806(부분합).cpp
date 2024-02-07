#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    int leftIdx = 0;
    int rightIdx = 0;
    int sum = 0;
    int minLen = 100001;
    vector <int> v;

    cin >> N >> S;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    while (leftIdx <= rightIdx) {
        if (sum >= S) {
            sum -= v[leftIdx];
            leftIdx++;
            minLen = min(minLen, rightIdx - leftIdx + 1);
        }
        else if (rightIdx == N) {
            break;
        }
        else {
            sum += v[rightIdx];
            rightIdx++;
        }
    }

    if (minLen == 100001) {
        cout << 0;
    }
    else {
        cout << minLen;
    }

    return 0;
}
