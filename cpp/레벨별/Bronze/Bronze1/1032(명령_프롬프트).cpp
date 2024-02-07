#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, size;
    vector <string> v;
    string str;
    string ans = "";

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> str;

        v.push_back(str);
    }

    size = v[0].size();

    for (int i = 0; i < size; i++) {
        bool check = false;

        for (int j = 0; j < v.size() - 1; j++) {
            if (v[j][i] != v[j + 1][i])
                check = true;
        }

        if (check)
            ans += "?";
        else
            ans += v[0][i];
    }

    cout << ans;
}