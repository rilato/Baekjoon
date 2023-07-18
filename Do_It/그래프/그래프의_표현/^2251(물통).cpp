// Queue에 3개의 물통의 물 양을 넣어서 관리해준다. 중복된 탐색을 피하기 위해서 Visit[][][] 3차원 배열을 사용한다.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int A, B, C;
bool Visit[201][201][201];

vector<int> V;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    queue<pair<pair<int, int>, int>> Q;

    // 맨 처음, A와 B는 비어있고 C만 차있는 상황
    Q.push(make_pair(make_pair(0, 0), C));

    while (!Q.empty()) {
        int a = Q.front().first.first;
        int b = Q.front().first.second;
        int c = Q.front().second;

        Q.pop();

        // Visit[a][b][c] = true의 의미는 A물통에 a의 물양이, B물통에 b의 물양이, C물통에 c의 물양이 들어 있을 때는 이미 탐색했습니다 라는 의미
        if (Visit[a][b][c] == true) continue;

        Visit[a][b][c] = true;

        if (a == 0) V.push_back(c);

        // A물통에서 B물통으로 줄 때, 물이 넘친다면 B가 꽉찰 때 까지만 물 주기
        if (a + b > B) Q.push(make_pair(make_pair(a + b - B, B), c));
        // 물이 넘치지 않는다면 A의 물 다 주기
        else Q.push(make_pair(make_pair(0, a + b), c));

        // A물통에서 C물통으로 줄 때
        if (a + c > C) Q.push(make_pair(make_pair(a + c - C, b), C));
        else Q.push(make_pair(make_pair(0, b), a + c));

        // B물통에서 A물통으로 줄 때
        if (b + a > A) Q.push(make_pair(make_pair(A, b + a - A), c));
        else Q.push(make_pair(make_pair(b + a, 0), c));

        // B물통에서 C물통으로 줄 때
        if (b + c > C) Q.push(make_pair(make_pair(a, b + c - C), C));
        else Q.push(make_pair(make_pair(a, 0), b + c));

        // C물통에서 A물통으로 줄 때
        if (c + a > A) Q.push(make_pair(make_pair(A, b), c + a - A));
        else Q.push(make_pair(make_pair(c + a, b), 0));

        // C물통에서 B물통으로 줄 때
        if (c + b > B) Q.push(make_pair(make_pair(a, B), c + b - B));
        else Q.push(make_pair(make_pair(a, b + c), 0));
    }

    sort(V.begin(), V.end());

    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";

    return 0;
}
