#include <iostream>
#include <vector>

using namespace std;

int N;
int tree[26][2];
char root, l, r;
void preOrder(int now);
void inOrder(int now);
void postOrder(int now);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> root >> l >> r;

        int idx = root - 'A';

        // 자식 노드가 없을 경우, -1을 저장
        if (l == '.') {
            tree[idx][0] = -1;
        }
        else {
            tree[idx][0] = l - 'A';
        }

        if (r == '.') {
            tree[idx][1] = -1;
        }
        else {
            tree[idx][1] = r - 'A';
        }
    }

    preOrder(0);
    cout << '\n';

    inOrder(0);
    cout << '\n';

    postOrder(0);

    return 0;
}

// preOrder (중간 -> 왼쪽 -> 오른쪽)
void preOrder(int now) {
    // 현재 노드가 자식 노드가 없다면 (자식이 -1이라면) 리턴
    if (now == -1) {
        return;
    }

    cout << (char)(now + 'A');  // 현재 노드
    preOrder(tree[now][0]);     // 왼쪽 노드
    preOrder(tree[now][1]);     // 오른쪽 노드
}

// inOrder (왼쪽 -> 중간 -> 오른쪽)
void inOrder(int now) {
    // 현재 노드가 자식 노드가 없다면 (자식이 -1이라면) 리턴
    if (now == -1) {
        return;
    }

    inOrder(tree[now][0]);      // 왼쪽 노드
    cout << (char)(now + 'A');  // 현재 노드
    inOrder(tree[now][1]);      // 오른쪽 노드
}

// postOrder (왼쪽 -> 오른쪽 -> 중간)
void postOrder(int now) {
    // 현재 노드가 자식 노드가 없다면 (자식이 -1이라면) 리턴
    if (now == -1) {
        return;
    }

    postOrder(tree[now][0]);    // 왼쪽 노드
    postOrder(tree[now][1]);    // 오른쪽 노드
    cout << (char)(now + 'A');  // 현재 노드
}
