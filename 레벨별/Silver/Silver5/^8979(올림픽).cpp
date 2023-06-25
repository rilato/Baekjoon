// 40�� Ǯ��
// sort ���� Ǯ��Ҵ�.

#include <iostream>

using namespace std;

int N, K;
int gold[1001];
int silver[1001];
int bronze[1001];
// ����� 1����� ����
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



// ���� Ǯ��
// pair�� 4���� ���� �����ϴ� ����� �˾ƾ��ϰ�, cmp�Լ��� �ۼ��ϴ� ����� �˾ƾ� �Ѵ�.

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
        //���� ��ũ�� ���� K��° ���� ���� ���� ������
            else if (a.second.second == b.second.second)
                return a.first.first == K;
    }

    return false;
}