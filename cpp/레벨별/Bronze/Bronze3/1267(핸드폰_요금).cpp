#include <iostream>

using namespace std;

int Y(int n);
int M(int n);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;
    int ySum = 0;
    int mSum = 0;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;

        ySum += Y(num);
        mSum += M(num);
    }

    if (ySum > mSum)
        cout << "M " << mSum;
    else if (ySum < mSum)
        cout << "Y " << ySum;
    else
        cout << "Y M " << mSum;
}

int Y(int n) {
    int portion = 10 * ((n / 30) + 1);

    return portion;
}

int M(int n) {
    int portion = 15 * ((n / 60) + 1);

    return portion;
}