#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vv_t;

vector<int> ans;          /* 用於存儲Result值 */
vector<bool> vis;
vv_t adj;
size_t cctv = 0;

/* 深度優先搜索*/
bool dfs(size_t depth, int here) {
    int i = 0;
    vis[here] = true;

    if (depth == 0 && adj[here].size() == 0) { 
        cctv++;
        return true; 
    }
    else {
        int flag = 0; 
        for (i = 0; i < adj[here].size(); i++) {
            if (vis[adj[here][i]] == false) {
                if (dfs(depth + 1, adj[here][i]) == false) {
                    flag = 1;
                }
            }
        }
        if (flag == 1) {
            cctv++;
            return true;
        }
        return false;
    }
}

void Solution() {
    int i = 0;
    int n = 0;
    int A, B, a, b;

    for (cin >> n; n > 0; n--) {
        cin >> A >> B;
        adj = vv_t(A);
        vis = vector<bool>(A, false);

        for (i = 0; i < B; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (i = 0; i < A; i++) {
            if (vis[i] == false) {
                dfs(0, i);
            }
        }

        //cout << cctv << endl;
        ans.push_back(cctv);
        cctv = 0;
    }
}

int main(void) {
    Solution();

    cout << "輸出：" << endl;
    for (auto e : ans) {
        cout << e << endl;
    }

    return 0;
}

