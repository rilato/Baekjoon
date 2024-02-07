#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, S, num;
stack <int> st;

int GCD(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> num;

        st.push(abs(S - num));
    }

    while (1) {
        if (st.size() == 1) {
            break;
        }

        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();

        st.push(GCD(num1, num2));
    }

    cout << st.top();

    return 0;
}

int GCD(int a, int b) {
    int c;

    while (b) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}
