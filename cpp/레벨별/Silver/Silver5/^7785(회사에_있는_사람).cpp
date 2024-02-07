// set�� ������, set�� ����ϱ� ���� iter�� ������.

// Ʋ�� Ǯ��
// �Ƹ��� �ð� �ʰ��� ���� �ʾ����� �ʹ�.

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

// ���� Ǯ��
// set�� ����Ѵ�.

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

    // string_map �� enter �̸� ����, �ƴϸ� �����ش�. 
    for (int i = 0; i < n; i++) {
        string name, work;

        cin >> name >> work;

        if (work == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    // ���� ����� ���� �ʿ�
    for (auto iter = s.rbegin(); iter != s.rend(); iter++)
        cout << *iter << "\n";
}