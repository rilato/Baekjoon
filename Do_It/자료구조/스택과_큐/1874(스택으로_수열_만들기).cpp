// s.top()을 top으로 받아주어, pop()을 진행했을 때에도 원래 top이었던 값에 접근할 수 있도록 한다.
// pop()을 한 후, top()을 하면 기존의 top()과 다른 top()이 된다!

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int num = 1;
    stack <int> s;

    cin >> n;

    vector <int> v(n, 0);
    vector <char> resultV;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= num) {
            while (v[i] >= num) {
                s.push(num++);
                resultV.push_back('+');
            }

            s.pop();
            resultV.push_back('-');
        }
        else {
            // pop 하기 전의 top()
            int top = s.top();
            // 한 개 pop()
            s.pop();

            if (top > v[i]) {
                cout << "NO";
                return 0;
            }
            else {
                resultV.push_back('-');
            }
        }
    }

    for (int i = 0; i < resultV.size(); i++) {
        cout << resultV[i] << '\n';
    }

    return 0;
}