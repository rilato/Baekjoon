#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int width, height, N, num1, num2;
int garoTemp = 0;
int seroTemp = 0;
int answer = 0;
vector <int> garo;
vector <int> sero;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> N;

    while (N--) {
        cin >> num1 >> num2;

        if (num1 == 0) {
            garo.push_back(num2);
        }
        else {
            sero.push_back(num2);
        }
    }

    garo.push_back(width);
    sero.push_back(height);

    sort(garo.begin(), garo.end());
    sort(sero.begin(), sero.end());

    for (int i = 0; i < garo.size(); i++) {
        for (int j = 0; j < sero.size(); j++) {
            int garoLen = garo[i] - garoTemp;
            int seroLen = sero[j] - seroTemp;

            seroTemp = sero[j];

            if (garoLen * seroLen > answer) {
                answer = garoLen * seroLen;
            }
        }

        garoTemp = garo[i];
        seroTemp = 0;
    }

    cout << answer;

    return 0;
}
