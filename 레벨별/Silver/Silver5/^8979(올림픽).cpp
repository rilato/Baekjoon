// 40점 풀이
// sort 없이 풀어보았다.

#include <iostream>

using namespace std;

int N, K;
int gold[1001];
int silver[1001];
int bronze[1001];
// 등수는 1등부터 시작
int ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        gold[a] = b;
        silver[a] = c;
        bronze[a] = d;
    }

    for (int i = 1; i <= N; i++) {
        if (gold[i] > gold[K])
            ans++;
        else if (gold[i] == gold[K] && silver[i] > silver[K])
            ans++;
        else if (silver[i] == silver[K] && bronze[i] > bronze[K])
            ans++;
    }

    cout << ans;

    return 0;
}



// 맞은 풀이
// pair로 4개의 값을 저장하는 방법을 알아야하고, cmp함수를 작성하는 방법을 알아야 한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

bool cmp(pair <pair <int, int>, pair <int, int>> a, pair <pair <int, int>, pair <int, int>> b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vector <pair <pair <int, int>, pair <int, int>>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        if (v[i].first.first == K) {
            cout << i + 1;
            return 0;
        }
    }
}

bool cmp(pair <pair <int, int>, pair <int, int>> a, pair <pair <int, int>, pair <int, int>> b) {
    if (a.first.second > b.first.second)
        return true;

    else if (a.first.second == b.first.second) {
        if (a.second.first > b.second.first)
            return true;
        else if (a.second.first == b.second.first)
            if (a.second.second > b.second.second)
                return true;
        //동일 랭크에 대해 K번째 나라가 제일 먼저 오도록
            else if (a.second.second == b.second.second)
                return a.first.first == K;
    }

    return false;
}