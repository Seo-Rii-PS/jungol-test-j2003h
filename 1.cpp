//
// Created by Seo_Hyun on 8/1/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, sum = 0;
    scanf("%d %d", &n, &m);
    auto vs = vector<vector<int>>((n + m) / 2, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t;
            scanf("%d", &t);
            if (i + j < (n + m) / 2) vs[i + j].push_back(t);
            else vs[n + m - 2 - i - j].push_back(t);
        }
    }
    for (auto &v:vs) {
        int cnt = 0, maxCnt = 0;
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] != v[i - 1]) {
                maxCnt = max(maxCnt, cnt + 1);
                cnt = 0;
            } else ++cnt;
        }
        maxCnt = max(maxCnt, cnt + 1);
        sum += v.size() - maxCnt;
    }
    printf("%d\n", sum);
}