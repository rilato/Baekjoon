#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int soongsil, korea, hanyang;

    cin >> soongsil >> korea >> hanyang;

    if (soongsil + korea + hanyang >= 100) {
        cout << "OK";
    }
    else {
        int temp = min(min(soongsil, korea), hanyang);

        if (temp == soongsil)
            cout << "Soongsil";
        else if (temp == korea)
            cout << "Korea";
        else
            cout << "Hanyang";
    }
}