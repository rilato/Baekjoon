#include <iostream>
#include <climits>

using namespace std;

string A, B;
int sizeGap;
int gap = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    // A의 크기는 항상 B보다 작거나 같다

    sizeGap = B.size() - A.size();

    for (int i = 0; i <= sizeGap; i++) {
        int cnt = 0;

        // 작은 크기인 A는 고정하고, A사이즈만큼 B를 잘라서 같은지 측정한다
        for (int j = 0; j < A.size(); j++) {
            if (A[j] != B[i + j]) {
                cnt++;
            }
        }

        gap = min(gap, cnt);
    }

    cout << gap;

    return 0;
}