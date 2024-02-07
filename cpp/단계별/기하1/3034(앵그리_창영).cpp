#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, W, H, number;
    int Diagonal;
    vector <int> v;

    cin >> N >> W >> H;

    Diagonal = sqrt(W * W + H * H);

    for (int i = 0; i < N; i++) {
        cin >> number;
        v.push_back(number);
    }

    for (int i = 0; i < N; i++) {
        if (v[i] <= Diagonal)
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }
}