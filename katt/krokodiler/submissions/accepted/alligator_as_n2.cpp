#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

#define next abacabadabacaba

const int MAX = 3000;
int field[MAX][MAX + 1];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int next[MAX][MAX][4];

bool canGo[MAX][MAX];

int main() {
    int n, m;
    scanf("%d%d\n", &n, &m);
    string dir("NESW.");
    for (int i = 0; i < n; i++) {
        char buf[MAX + 1];
        scanf("%s\n", buf);
        for (int j = 0; j < m; j++) {
            field[i][j] = dir.find(buf[j]);
        }
    }

    queue < pair<int, int> > q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || field[i - 1][j] < 4) {
                next[i][j][0] = i - 1;
            } else {
                next[i][j][0] = next[i - 1][j][0];
            }
            if (j == 0 || field[i][j - 1] < 4) {
                next[i][j][3] = j - 1;
            } else {
                next[i][j][3] = next[i][j - 1][3];
            }
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 || field[i + 1][j] < 4) {
                next[i][j][2] = i + 1;
            } else {
                next[i][j][2] = next[i + 1][j][2];
            }
            if (j == m - 1 || field[i][j + 1] < 4) {
                next[i][j][1] = j + 1;
            } else {
                next[i][j][1] = next[i][j + 1][1];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int bound = k % 2 == 0 ? n : m;
                if (field[i][j] == k && (next[i][j][k] == -1 || next[i][j][k] == bound)) {
                    canGo[i][j] = true;
                    q.push(make_pair(i, j));
                }
            }
        }
    }


    int ans = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        ans++;

        int i = p.first;
        int j = p.second;

        for (int k = 0; k < 4; k++) {
            int ni = i;
            int nj = j;
            if (dx[k] != 0) {
                ni = next[i][j][k];
            } else {
                nj = next[i][j][k];
            }
            if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                int nk = k ^ 2;
                next[ni][nj][nk] = next[i][j][nk];
                int bound = nk % 2 == 0 ? n : m;
                if (nk == field[ni][nj] && !canGo[ni][nj] && (next[ni][nj][nk] == -1 || next[ni][nj][nk] == bound)) {
                    canGo[ni][nj] = true;
                    q.push(make_pair(ni, nj));
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
