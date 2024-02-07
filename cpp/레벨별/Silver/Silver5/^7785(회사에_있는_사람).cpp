// set의 사용법과, set을 출력하기 위한 iter를 익힌다.

// 틀린 풀이
// 아마도 시간 초과가 나지 않았을까 싶다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string name, enter;

    cin >> n;

    vector <string> v;

    for (int i = 0; i < n; i++) {
        cin >> name >> enter;

        if (enter == "enter") {
            v.push_back(name);
        }

        else {
            for (int j = 0; j < v.size(); j++) {
                if (name == v[j])
                    v.erase(v.begin() + j);
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}

// 맞은 풀이
// set을 사용한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    set<string> s;

    cin >> n;

    // string_map 에 enter 이면 삽입, 아니면 지워준다. 
    for (int i = 0; i < n; i++) {
        string name, work;

        cin >> name >> work;

        if (work == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    // 역순 출력을 위해 필요
    for (auto iter = s.rbegin(); iter != s.rend(); iter++)
        cout << *iter << "\n";
}