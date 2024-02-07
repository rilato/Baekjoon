#include <iostream>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    //하나의 교차점을 만들기 위해서는 선분이 2개 필요
    //선분 2개는 꼭지점 4개로 구성
    //그러므로 n개의 꼭지점으로 구성된 볼록 다각형은 하나의 교차점을 위해 4개의 꼭지점을 선택해야하므로
    //nC4가 정답이다.

    cout << N * (N - 1) * (N - 2) * (N - 3) / 24;

    return 0;
}
