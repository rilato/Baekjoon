#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int gap = 2100000000;
vector <vector <int>> v;
vector <int> start;
vector <bool> visited;

void Combination(int depth, int num, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N, vector <int>(N));
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i < N - 1; i++) {
        Combination(0, 0, i);
    }

    cout << gap;

    return 0;
}

void Combination(int depth, int num, int m) {
    if (depth == m) {
        vector <int> link;

        int startSum = 0;
        int linkSum = 0;

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                link.push_back(i);
            }
        }

        for (int i = 0; i < start.size(); i++) {
            for (int j = 0; j < start.size(); j++) {
                if (i != j) {
                    startSum += v[start[i]][start[j]];
                }
            }
        }

        for (int i = 0; i < link.size(); i++) {
            for (int j = 0; j < link.size(); j++) {
                if (i != j) {
                    linkSum += v[link[i]][link[j]];
                }
            }
        }

        gap = min(gap, abs(startSum - linkSum));

        return;
    }

    for (int i = num; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            start.push_back(i);
            Combination(depth + 1, i, m);
            start.pop_back();
            visited[i] = false;
        }
    }
}