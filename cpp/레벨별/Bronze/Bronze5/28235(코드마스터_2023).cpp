#include <iostream>

using namespace std;

string S;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    if (S == "SONGDO") {
        cout << "HIGHSCHOOL";
    }
    else if (S == "CODE") {
        cout << "MASTER";
    }
    else if (S == "2023") {
        cout << "0611";
    }
    else {
        cout << "CONTEST";
    }

    return 0;
}