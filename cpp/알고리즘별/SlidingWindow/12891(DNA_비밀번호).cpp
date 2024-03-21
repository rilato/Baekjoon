#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
string S;
bool flag = false;
int cnt = 0;
vector <int> dna(4);
vector <int> alpha(4);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> S;

    for (int i = 0; i < 4; ++i) {
        cin >> dna[i];
    }

    int start = 0;
    int finish = M - 1;

    for (int i = start; i <= finish; ++i) {
        if (S[i] == 'A') {
            ++alpha[0];
        }
        if (S[i] == 'C') {
            ++alpha[1];
        }
        if (S[i] == 'G') {
            ++alpha[2];
        }
        if (S[i] == 'T') {
            ++alpha[3];
        }
    }

    while (finish != N) {
        if (alpha[0] >= dna[0] && alpha[1] >= dna[1] && alpha[2] >= dna[2] && alpha[3] >= dna[3]) {
            ++cnt;
        }

        if (S[start] == 'A') {
            --alpha[0];
        }
        if (S[start] == 'C') {
            --alpha[1];
        }
        if (S[start] == 'G') {
            --alpha[2];
        }
        if (S[start] == 'T') {
            --alpha[3];
        }

        start++;
        finish++;

        if (S[finish] == 'A') {
            ++alpha[0];
        }
        if (S[finish] == 'C') {
            ++alpha[1];
        }
        if (S[finish] == 'G') {
            ++alpha[2];
        }
        if (S[finish] == 'T') {
            ++alpha[3];
        }
    }

    cout << cnt;

    return 0;
}
