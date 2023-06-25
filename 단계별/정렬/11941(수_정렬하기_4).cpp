#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v;

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), greater <int>());

    for (int i = 0; i < input; i++) {
        cout << v[i] << '\n';
    }
}



// compare를 이용한 다른 풀이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int& a, int& b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v;

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < input; i++) {
        cout << v[i] << '\n';
    }
}

bool compare(int& a, int& b) {
    return a > b;
}