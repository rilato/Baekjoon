#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, p, a, c, g, t;
    string dna;
    map <char, int> m;

    cin >> s >> p >> dna >> a >> c >> g >> t;

    m['A'] = a;
    m['C'] = c;
    m['G'] = g;
    m['T'] = t;

    int lp = 0;
    int rp = 0;
    int cnt = 0;
    map <char, int> check;

    check['A'] = 0;
    check['C'] = 0;
    check['G'] = 0;
    check['T'] = 0;

    while (1) {
        if (rp == s)
            break;

        // 오른쪽 윈도우 슬라이딩
        if (dna[rp] == 'A')
            check['A']++;
        if (dna[rp] == 'C')
            check['C']++;
        if (dna[rp] == 'G')
            check['G']++;
        if (dna[rp] == 'T')
            check['T']++;

        rp++;

        // 글자 사이즈가 p라면 윈도우 슬라이딩
        if (rp - lp == p) {
            // A, C, G, T 개수의 조건을 만족하는 경우 카운팅
            if (check['A'] >= m['A'] && check['C'] >= m['C'] && check['G'] >= m['G'] && check['T'] >= m['T']) {
                cnt++;
            }

            if (dna[lp] > 0)
                check[dna[lp]]--;   // 슬라이딩 직전의 맨 왼쪽 문자 개수 1개 줄이기

            // 왼쪽 윈도우 슬라이딩
            lp++;
        }
    }

    cout << cnt;

    return 0;
}