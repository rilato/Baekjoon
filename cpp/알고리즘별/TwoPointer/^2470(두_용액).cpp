// 틀린 풀이
// 반례
// 5
// -2 4 1 -1 99
// 정답 : -1 1 / 내 답 : -2 1

// gap이 최소가 되는 값 계산과, 투 포인터의 계산은 달라야 한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int n, x;
int gap = INT_MAX;
int num1, num2;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int left, right;

    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    left = 0;
    right = n - 1;

    while (left < right) {
        cout << "left : " << left << ", right : " << right << ", v[left] : " << v[left] << ", v[right] : " << v[right] << '\n';
        if (abs(v[left] + v[right]) < gap) {
            gap = abs(v[left] + v[right]);
            num1 = v[left];
            num2 = v[right];
            // 여기서 임의로 right--를 해주면 안된다!
            right--;
        }
        else if (v[left] + v[right] > 0) {
            right--;
        }
        else {
            left++;
        }
    }

    cout << num1 << " " << num2;

    return 0;
}


// 맞은 풀이

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int n, x;
int gap = INT_MAX;
int num1, num2;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int left, right;

    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    left = 0;
    right = n - 1;

    while (left < right) {
        //cout << "left : " << left << ", right : " << right << ", v[left] : " << v[left] << ", v[right] : " << v[right] << '\n';
        if (abs(v[left] + v[right]) < gap) {
            gap = abs(v[left] + v[right]);
            num1 = v[left];
            num2 = v[right];
        }
        
        if (v[left] + v[right] > 0) {
            right--;
        }
        else {
            left++;
        }
    }

    cout << num1 << " " << num2;

    return 0;
}
