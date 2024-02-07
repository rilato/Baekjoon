#include <iostream>

using namespace std;

string arr[5];
bool fbi = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++) {
        if (arr[i].find("FBI", 0) != -1) {
            cout << i + 1 << " ";
            fbi = true;
        }
    }

    if (!fbi) {
        cout << "HE GOT AWAY!";
    }

    return 0;
}